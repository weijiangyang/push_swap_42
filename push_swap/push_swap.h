/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:09:34 by weiyang           #+#    #+#             */
/*   Updated: 2025/07/04 16:45:00 by weiyang          ###   ########.fr       */
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
}	t_list;

void    swap(t_list **list);
void    sa(t_list **list);
void    sb(t_list **list);
void    ss(t_list **list_a, t_list **list_b);
void    pa(t_list **list_a, t_list **list_b);
void    pb(t_list **list_b, t_list **list_a);
void    rotate(t_list **list);
void    ra(t_list **list);
void    rb(t_list **list);
void    rr(t_list **list_a, t_list **list_b);
void    rrotate(t_list **list);
void    rra(t_list **list);
void    rrb(t_list **list);
void    rrr(t_list **list_a, t_list **list_b);
int     is_sorted_asc(t_list *list);
int     is_sorted_desc(t_list *list);
int     count_max_bits(t_list *list);
int    sort(t_list **list_a, t_list **list_b);
t_list *new_node(int value);
long    ft_atoi(char *s);
int     is_valid_int(char *str);
int     has_duplicate(t_list *list);
int	ft_list_size(t_list *list);
void assign_indexes(t_list *lst);
t_list  *parse_list(int argc, char **argv);
int     get_max_index(t_list *list);
int     bring_max_to_top(t_list **list, int max_index);








#endif
