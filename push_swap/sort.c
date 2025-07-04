/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:23:27 by weiyang           #+#    #+#             */
/*   Updated: 2025/07/04 19:05:42 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted_asc(t_list *list)
{
        while (list && list->next)
        {
                if (list->index > list->next->index)
                        return (0);
                list = list->next;
        }
        return (1);
}

int is_sorted_desc(t_list *list)
{
        while (list && list->next)
        {
                if (list->index < list->next->index)
                        return (0);
                list = list->next;
        }
        return (1);
}

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

int count_max_bits(t_list *list)
{
        int max_bits;
        int max_index;
        t_list *first;

        max_bits = 0;
        first = list;
        if (!first)
                return (0);
        max_index = get_max_index(list);
        while ((max_index >> max_bits) != 0)
                max_bits++;
        return (max_bits);
}

int     bring_max_to_top(t_list **list, int max_index)
{
        int     size;
        int     pos;
        t_list  *current;
        int     i;
        int     count;

        count = 0;
        i = 0;
        pos = 0;
        size = ft_list_size(*list);
        current = *list;
        while (current && current->index != max_index)
        {
                current = current->next;
                pos++;
        }
        if (pos < size / 2)
        {
                while (i < pos)
                {
                        rb(list);
                        count++;
                        i++;
                }
        }
        else
        {
                while (i < size - pos)
                {
                        rrb(list);
                        count++;
                        i++;
                }
        }
        return (count);

}

/*int	sort(t_list **list_a, t_list **list_b)
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
}*/

int sort(t_list **list_a, t_list **list_b)
{
        int     list_size = ft_list_size(*list_a);
        int chunk_size = list_size / 5;
        int current_chunk = 1;
        int limit = chunk_size * current_chunk;
        int    count_in_b = 0;
        int     count_actions;

        count_actions = 0;
        while (*list_a)
        {
                if ((*list_a)->index <= limit)
                {
                        pb(list_b, list_a);
                        count_in_b++;
                        count_actions++;
                        if ((*list_b)->index < limit - (chunk_size / 2))
                        {
                                count_actions++;
                                ra(list_b); // pour mieux répartir
                        }   
                }
                else
                {
                        	ra(list_a);
				count_actions++;
                }
                if (count_in_b == limit) // passer au prochain chunk
                        current_chunk++;
                limit = chunk_size * current_chunk;
        }

        // ensuite : vider B en mettant le max au top
        while (*list_b)
        {
                int max = get_max_index(*list_b);
                bring_max_to_top(list_b, max);
                pa(list_a, list_b);
                count_actions++;
        }
        return (count_actions);
}
