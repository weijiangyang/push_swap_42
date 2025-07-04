/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:23:27 by weiyang           #+#    #+#             */
/*   Updated: 2025/07/04 15:30:47 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_asc(t_list *list)
{
	while (list && list->next)
	{
		if (list->index > list->next->index)
			return (0);
		list = list->next;
	}
	return (1);
}

int	is_sorted_desc(t_list *list)
{
	while (list && list->next)
	{
		if (list->index < list->next->index)
			return (0);
		list = list->next;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

int	count_max_bits(t_list *list)
{
	int	max_bits;
	int	max_index;
	t_list	*first;

	max_bits = 0;
	first = list;
	if(!first)
		return (0);
	max_index = first->index;
	while (first)
	{
		if (max_index < first->index)
			max_index = first->index;
		first = first -> next;
	}
	while ((max_index >> max_bits)!= 0)
		max_bits++;
	return (max_bits);
}
 		
int	sort(t_list **list_a, t_list **list_b)
{
	int	size;
	int	i;
	int	max_bits;
	int	j;
	int	count;

	count = 0;
	max_bits = count_max_bits(*list_a);
	j = 0;

	while (j < max_bits)
	{
		i = 0;
		size = ft_list_size(*list_a);
		while(i < size)
		{
			if (is_sorted_asc(*list_a))
				break;
			if (((*list_a)->index >> j)& 1) 
			{
				ra(list_a);
				count++;
			}
			else
			{
				if (i == size -1 )
					break;
				pb(list_b, list_a);
				count++;
			}
			i++;
		}			
		while (*list_b)
		{
			pa(list_a, list_b);
			count++;
		}
		j++;
	}
	return (count);
}
