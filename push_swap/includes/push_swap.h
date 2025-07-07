/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:09:34 by weiyang           #+#    #+#             */
/*   Updated: 2025/07/07 17:29:04 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

typedef	struct	s_list
{
	int	value;
	int	index;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

int    swap(t_list **list);
int    sa(t_list **list);
int    sb(t_list **list);
int    ss(t_list **list_a, t_list **list_b);
int    pa(t_list **list_a, t_list **list_b);
int    pb(t_list **list_b, t_list **list_a);
int    rotate(t_list **list);
int    ra(t_list **list);
int    rb(t_list **list);
int    rr(t_list **list_a, t_list **list_b);
int    rrotate(t_list **list);
int    rra(t_list **list);
int    rrb(t_list **list);
int    rrr(t_list **list_a, t_list **list_b);
int     is_sorted_asc(t_list *list);
int     is_sorted_desc(t_list *list);
int     count_max_bits(t_list *list);
int    sort(t_list **list_a, t_list **list_b);
t_list *new_node(int value);
long    ft_atoi(char *s);
int     is_valid_int(char *str);
int     has_duplicate(t_list *list);
int	ft_list_size(t_list *list);
void	assign_indexes(t_list *lst);
t_list  *parse_list(int argc, char **argv);
int     get_max_index(t_list *list);
int     bring_max_to_top(t_list **list, int max_index);








#endif
