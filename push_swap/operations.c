/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:59:17 by weiyang           #+#    #+#             */
/*   Updated: 2025/07/03 15:25:05 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sa(t_list **list_a)
{
	t_list	*next;
	t_list	*first;
	t_list	*second;

	if (!list || !*list || !(*list)->next)
		return ;
	first = *list;
	second = (*list)->next;
	first->next = second->next;
	second->next = first;
	*list = second;
}

void    sb(t_list **list_b)
{
        t_list  *next;
        t_list  *first;
        t_list  *second;

        if (!list || !*list || !(*list)->next)
                return ;
        first = *list;
        second = (*list)->next;
        first->next = second->next;
        second->next = first;
        *list = second;
}

void	ss(t_list **list_a, t_list **list_b)
{
	sa(list_a);
	sb(list_b);
}

void	pa(t_list **list_a, t_list **list_b)
{
	t_list	*list_first_b;

	if (!list_a || !*list_b)
		return ;
	list_first_b = *list_b;
	*list_b = *list_b->next;
	list_first_b->next = *list_a;
	*list_a = list_first_b;
} 	

void    pa(t_list **list_b, t_list **list_a)
{
        t_list  *list_first_a;

        if (!list_a || !*list_b)
                return ;
        list_first_a = *list_a;
        *list_a = *list_a->next;
        list_first_a->next = *list_b;
        *list_b = list_first_a;
}

void	ra(t_list **list_a)
{
	t_list	*first;
	t_list	*last;
	
	*first = *list_a;
	*last = *list_a;
	while(last)
		last = last->next;	
