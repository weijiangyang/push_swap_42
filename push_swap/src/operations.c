/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:59:17 by weiyang           #+#    #+#             */
/*   Updated: 2025/07/06 16:44:10 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	swap(t_list **list)
{
	t_list	*first;
	t_list	*second;

	if (!list || !*list || !(*list)->next)
		return (0);
	first = *list;
	second = (*list)->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	*list = second;
	return (1);
}

int    sa(t_list **list)
{
	if (swap(list))
		write(1, "sa\n", 3);
	return (1);
}

int	sb(t_list **list)
{
	if (swap(list))
		write(1, "sb\n", 3);
	return (1);
}

int	ss(t_list **list_a, t_list **list_b)
{
	if (swap(list_a) && swap(list_b))
		write(1, "ss\n", 3);
	return (1);
}

int p(t_list **list_a, t_list **list_b)
{
    t_list *list_b_first;

    if (!list_b || !*list_b)
        return (0);

    list_b_first = *list_b;
    *list_b = list_b_first->next;
    if (*list_b)
        (*list_b)->prev = NULL;

    list_b_first->next = *list_a;
    if (*list_a)
        (*list_a)->prev = list_b_first;

    list_b_first->prev = NULL;
    *list_a = list_b_first;
    return (1);
}

int    pa(t_list **list_a, t_list **list_b)
{
	if (p(list_a, list_b))
	{
		write(1, "pa\n", 3);
		return (1);
	}
	return (0);
}

int	pb(t_list **list_a, t_list **list_b)
{
	if (p(list_b, list_a))
	{
		write(1, "pb\n", 3);
		return (1);
	}
	return (0);
}
	
int	rotate(t_list **list)
{
	t_list	*first;
	t_list	*last;
	t_list	*second;

	if (!list || !*list || !(*list)->next)
		return (0);
	first = *list;
	second = (*list)->next;
	second -> prev = NULL;
	last = *list;
	while(last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	*list = second;
	return (1);
}

int	ra(t_list **list)
{
	if (rotate(list))
	{
		write (1, "ra\n", 3);
		return (1);
	}
	return (0);
}

int	rb(t_list **list)
{
	if (rotate(list))
	{
		write (1, "rb\n", 3);
		return (1);
	}
	return (0);
}

int	rr(t_list **list_a, t_list **list_b)
{
	if (rotate(list_a) && rotate(list_b))
	{
		write(1, "rr\n", 3);
		return (1);
	}
	return (0);
}

int	rrotate(t_list **list)
{
	t_list	*first;
	t_list	*last;
	t_list	*before_last;

	if(!list || !*list || !(*list)->next)
		return (0);
	first = *list;
	before_last = *list;

	while (before_last->next->next)
		before_last = before_last->next;
	last = before_last->next;
	last->prev = NULL;
	before_last->next = NULL;
	last->next = first;
	first->prev = last;
	*list = last;
	return (1);
}
	
int	rra(t_list **list)
{
	if (rrotate(list))
	{
		write (1, "rra\n", 4);
		return (1);
	}
	return (0);
}

int	rrb(t_list **list)
{
	if (rrotate(list))
	{
		write(1, "rrb\n", 4);
		return (1);
	}
	return (0);
}

int	rrr(t_list **list_a, t_list **list_b)
{
	if (rrotate(list_a) && rrotate(list_b))
	{
		write(1, "rrr\n", 4);
		return (1);
	}
	return (0);
}
	
int	ft_list_size(t_list *list)
{
	int	len;

	len = 0;
	while (list)
	{
		len++;
		list = list -> next;
	}
	return (len);
}
