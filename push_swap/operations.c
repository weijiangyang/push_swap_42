/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:59:17 by weiyang           #+#    #+#             */
/*   Updated: 2025/07/04 10:11:12 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(t_list **list)
{
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

void    sa(t_list **list)
{
	swap(list);
	write(1, "sa\n", 3);
}

void	sb(t_list **list)
{
	swap(list);
	write(1, "sb\n", 3);
}

void	ss(t_list **list_a, t_list **list_b)
{
	swap(list_a);
	swap(list_b);
	write(1, "ss\n", 3);
}

void	pa(t_list **list_a, t_list **list_b)
{
	t_list	*list_first_b;

	if (!*list_b)
		return ;
	list_first_b = *list_b;
	*list_b = *list_b->next;
	list_first_b->next = *list_a;
	*list_a = list_first_b;
	write (1, "pa\n", 3);
} 	

void    pb(t_list **list_b, t_list **list_a)
{
        t_list  *list_first_a;

        if (!*list_a)
                return ;
        list_first_a = *list_a;
        *list_a = *list_a->next;
        list_first_a->next = *list_b;
        *list_b = list_first_a;
	write(1, "pb\n", 3);
}

void	rotate(t_list **list)
{
	t_list	*first;
	t_list	*last;
	t_list	*second;

	if (!list || !*list || !(*list)->next)
		return ;
	first = *list;
	second = (*list)->next;
	last = *list;
	while(last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	*list = second;
}

void	ra(t_list **list)
{
	rotate(list);
	write (1, "ra\n", 3);
}

void	rb(t_list **list)
{
	rotate(list);
	write (1, "rb\n", 3);
}

void	rr(t_list **list_a, t_list **list_b)
{
	rotate(list_a);
	rotate(list_b);
	write(1, "rr\n", 3);
}

void	rrotate(t_list **list)
{
	t_list	*first;
	t_list	*last;
	t_list	*before_last;

	if(!list || !*list || !(*list)->next)
		return ;
	first = *list;
	before_last = *list;

	while (before_last->next->next)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = first;
	*list = last;
}
	
void	rra(t_list **list)
{
	rrotate(list);
	write (1, "rra\n", 4);
}

void	rrb(t_list **list)
{
	rrotate(list);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **list_a, t_list **list_b)
{
	rrotate(list_a);
	rrotate(list_b);
	write(1, "rrr\n", 4);
}
	

