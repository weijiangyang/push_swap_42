/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:23:27 by weiyang           #+#    #+#             */
/*   Updated: 2025/07/12 18:16:57 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int get_max_index(t_list *list)
{
	int max_index;
	t_list *first;

	first = list;
	if (!first)
		return (0);
	max_index = first->index;
	while (first)
	{
		if (max_index < first->index)
			max_index = first->index;
		first = first->next;
	}
	return (max_index);
}

/*int cal_cost_a(t_list *a, t_list *target)
{
	int pos;
	int size;
	t_list *tmp;
	int min;

	min = INT_MAX;
	pos = 0;
	size = ft_list_size(a);
	tmp = a;
	while (tmp)
	{
		if (tmp->index > target->index && tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
	}
	if (min == INT_MAX)
	{
		tmp = a;
		while (tmp)
		{
			if (tmp->index < min)
				min = tmp->index;
			tmp = tmp->next;
		}
	}
	tmp = a;
	while (tmp)
	{
		if (tmp->index == min)
			break;
		pos++;
		tmp = tmp->next;
	}
	if (pos < size / 2)
		return (pos);
	else
		return (-(size - pos));
}*/
int cal_cost_a(t_list *a, t_list *target)
{
	int		pos = 0;
	int		min = INT_MAX;
	int		size = ft_list_size(a);
	t_list	*tmp = a;

	// Cherche l’élément avec le plus petit index > target->index
	while (tmp)
	{
		if (tmp->index > target->index && tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
	}

	// Si aucun index > target trouvé, prendre l’élément avec l’index minimal
	if (min == INT_MAX)
	{
		tmp = a;
		while (tmp)
		{
			if (tmp->index < min)
				min = tmp->index;
			tmp = tmp->next;
		}
	}

	// Trouve la position de l'élément avec l'index `min`
	pos = 0;
	tmp = a;
	while (tmp)
	{
		if (tmp->index == min)
			break;
		pos++;
		tmp = tmp->next;
	}

	// Retourne le coût optimisé
	if (pos <= size / 2)
		return (pos);
	else
		return (pos - size); // valeur négative => rotate vers le bas
}

int cal_cost_b(t_list *b, t_list *target)
{
	int pos;
	int size;
	t_list *tmp;

	size = ft_list_size(b);
	pos = 0;
	if (!target)
		return (0);
	tmp = b;
	while (tmp && tmp->index != target->index)
	{
		tmp = tmp->next;
		pos++;
	}
	if (!tmp)
		return (0);
	if (pos < size / 2)
		return (pos);
	else
		return (-1 * (size - pos));
}

int total_moves(t_list *a, t_list *b, t_list *target)
{
	int cost_a;
	int cost_b;
	int total_moves;

	total_moves = 0;
	cost_a = cal_cost_a(a, target);
	cost_b = cal_cost_b(b, target);
	if (cost_a > 0 && cost_b > 0)
	{
		if (cost_a >= cost_b)
			total_moves = cost_a;
		else
			total_moves = cost_b;
	}
	else if (cost_a < 0 && cost_b < 0)
	{
		if (cost_a <= cost_b)
			total_moves = -cost_a;
		else
			total_moves = -cost_b;
	}
	else if (cost_a > 0 && cost_b < 0)
		total_moves = cost_a - cost_b;
	else if (cost_a < 0 && cost_b > 0)
		total_moves = cost_b - cost_a;
	return (total_moves);
}

t_move *get_best_move(t_list *a, t_list *b)
{
	int min_moves;
	t_list *tmp;
	t_move *best;
	int cost_a;
	int cost_b;
	int total;

	if (!a || !b)
		return (NULL);
	min_moves = INT_MAX;
	tmp = b;
	best = malloc(sizeof(t_move));
	if (!best)
		return (NULL);
	while (tmp)
	{
		total = total_moves(a, b, tmp);
		if (total < min_moves)
		{
			cost_a = cal_cost_a(a, tmp);
			cost_b = cal_cost_b(b, tmp);
			min_moves = total;
			if (cost_a > 0)
				best->direction_a = 1;
			else
				best->direction_a = -1;
			if (cost_b > 0)
				best->direction_b = 1;
			else
				best->direction_b = -1;
			best->cost_a = cost_a;
			best->cost_b = cost_b;
			best->total = total;
		}
		tmp = tmp->next;
	}
	return (best);
}

int execute_move(t_list **a, t_list **b, t_move *move)
{
	int count_actions;
	int i;
	int cost_a;
	int cost_b;
	int total;
	int direction_a;
	int direction_b;

	cost_a = move->cost_a;
	cost_b = move->cost_b;
	total = move->total;
	direction_a = move->direction_a;
	direction_b = move->direction_b;
	i = 0;
	count_actions = 0;
	if (direction_a == 1 && direction_b == 1)
	{
		if (cost_a >= cost_b)
		{
			while (i < cost_b)
			{
				count_actions += rr(a, b);
				i++;
			}
			i = 0;
			while (i < cost_a - cost_b)
			{
				count_actions += ra(a);
				i++;
			}
		}
		else
		{
			i = 0;
			while (i < cost_a)
			{
				count_actions += rr(a, b);
				i++;
			}
			i = 0;
			while (i < cost_b - cost_a)
			{
				count_actions += rb(b);
				i++;
			}
		}
	}
	else if (direction_a == 1 && direction_b == -1)
	{
		i = 0;
		while (i < cost_a)
		{
			count_actions += ra(a);
			i++;
		}
		i = 0;
		while (i < -cost_b)
		{
			count_actions += rrb(b);
			i++;
		}
	}
	else if (direction_a == -1 && direction_b == 1)
	{
		i = 0;
		while (i < -cost_a)
		{
			count_actions += rra(a);
			i++;
		}
		i = 0;
		while (i < cost_b)
		{
			count_actions += rb(b);
			i++;
		}
	}

	else if (direction_a == -1 && direction_b == -1)
	{
		if (-cost_a >= -cost_b)
		{
			while (i < -cost_b)
			{
				count_actions += rrr(a, b);
				i++;
			}
			i = 0;
			while (i < -cost_a + cost_b)
			{
				count_actions += rra(a);
				i++;
			}
		}
		else
		{
			i = 0;
			while (i < -cost_a)
			{
				count_actions += rrr(a, b);
				i++;
			}
			i = 0;
			while (i < -cost_b + cost_a)
			{
				count_actions += rrb(b);
				i++;
			}
		}
	}
	count_actions += pa(a, b);
	return (count_actions);
}

int greedy_sort(t_list **a, t_list **b)
{
	int count_actions;
	t_move *move;

	count_actions = 0;
	while (*b)
	{
		move = get_best_move(*a, *b);
		count_actions += execute_move(a, b, move);
		free(move);
	}
	return count_actions;
}

int get_min_position(t_list *list_a)
{
	int pos;
	t_list *tmp;
	int min;
	int min_pos;

	min = INT_MAX;
	pos = 0;
	min_pos = 0;
	tmp = list_a;
	while (tmp)
	{
		if (tmp->index < min)
		{
			min = tmp->index;
			min_pos = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	return (min_pos);
}

// chunk
int sort(t_list **list_a, t_list **list_b)
{
	int list_size = ft_list_size(*list_a);
	int chunk_size = list_size / 4;
	int current_chunk = 1;
	int limit = chunk_size * current_chunk;
	int count_in_b = 0;
	int count_actions;

	//	if (chunk_size == 0)
	//	        chunk_size = 1;
	count_actions = 0;
	while (ft_list_size(*list_a) > 2)
	{
		if ((*list_a)->index < limit)
		{
			pb(list_a, list_b);
			count_in_b++;
			count_actions++;
			if (*list_b && (*list_b)->index < limit - (chunk_size / 2))
			{
				count_actions += rb(list_b); // pour mieux répartir
			}
		}
		else
		{// Pour éviter de tourner en rond trop longtemps, garde un compteur de rotations
			static int safe_rotate = 0;
			safe_rotate++;
			if (safe_rotate > ft_list_size(*list_a)) // boucle complète sans pb
			{
				current_chunk++; // forcer le passage au prochain chunk
				limit = chunk_size * current_chunk;
				safe_rotate = 0;
			}
			count_actions += ra(list_a);
			
		}
		if (count_in_b >= chunk_size * current_chunk) // passer au prochain chunk
			current_chunk++;
		limit = chunk_size * current_chunk;
	}
	count_actions += greedy_sort(list_a, list_b);

	// Final rotation to bring smallest element to top
	/*	int min_pos = get_min_position(*list_a); // You’ll need to implement this
		if (min_pos < ft_list_size(*list_a) / 2)
			while (min_pos-- > 0)
				count_actions += ra(list_a);
		else
			while (min_pos++ < ft_list_size(*list_a))
				count_actions += rra(list_a);*/
	/*int min_pos = get_min_position(*list_a);
	int size = ft_list_size(*list_a);

	if (min_pos < size / 2)
	{
		while (min_pos-- > 0)
			count_actions += ra(list_a);
	}
	else
	{
		int rotations = size - min_pos;
		while (rotations-- > 0)
			count_actions += rra(list_a);
	}*/

	return (count_actions);
}
