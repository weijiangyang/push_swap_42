/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 13:34:02 by weiyang           #+#    #+#             */
/*   Updated: 2025/07/12 17:56:41 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/push_swap.h"


void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *tmp;

    if (!lst || !new)
        return;
    if (*lst == NULL)
    {
        *lst = new;
        return;
    }
    tmp = *lst;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = new;
}

t_list *ft_lstnew_index(int index)
{
    t_list *new_node;

    new_node = malloc(sizeof(t_list));
    if (!new_node)
        return (NULL);
    new_node->index = index;
    new_node->next = NULL;
    return (new_node);
}
void print_list(t_list *list)
{
    while (list)
    {
        printf("%d -> ", list->index);
        list = list->next;
    }
    printf("NULL\n");
}

int main(void)
{
    t_list *a = NULL;
    t_list *b = NULL;

    // Ajouter manuellement des éléments avec index
    // Ex: liste de 5 éléments avec indices dans le désordre
    ft_lstadd_back(&a, ft_lstnew_index(4));
    ft_lstadd_back(&a, ft_lstnew_index(2));
    ft_lstadd_back(&a, ft_lstnew_index(5));
    ft_lstadd_back(&a, ft_lstnew_index(1));
    ft_lstadd_back(&a, ft_lstnew_index(3));
    ft_lstadd_back(&a, ft_lstnew_index(13));
     ft_lstadd_back(&a, ft_lstnew_index(7));
    ft_lstadd_back(&a, ft_lstnew_index(8));
    ft_lstadd_back(&a, ft_lstnew_index(6));
     ft_lstadd_back(&a, ft_lstnew_index(19));
    ft_lstadd_back(&a, ft_lstnew_index(9));
    ft_lstadd_back(&a, ft_lstnew_index(10));
   ft_lstadd_back(&a, ft_lstnew_index(17));
    ft_lstadd_back(&a, ft_lstnew_index(31));

   ft_lstadd_back(&a, ft_lstnew_index(14));
    ft_lstadd_back(&a, ft_lstnew_index(22));
    ft_lstadd_back(&a, ft_lstnew_index(51));
    ft_lstadd_back(&a, ft_lstnew_index(156));
    ft_lstadd_back(&a, ft_lstnew_index(32));
    ft_lstadd_back(&a, ft_lstnew_index(135));
     ft_lstadd_back(&a, ft_lstnew_index(73));
    ft_lstadd_back(&a, ft_lstnew_index(48));
    ft_lstadd_back(&a, ft_lstnew_index(65));
     ft_lstadd_back(&a, ft_lstnew_index(196));
    ft_lstadd_back(&a, ft_lstnew_index(49));
    ft_lstadd_back(&a, ft_lstnew_index(610));
   ft_lstadd_back(&a, ft_lstnew_index(170));
    ft_lstadd_back(&a, ft_lstnew_index(310));
    printf("Avant tri:\n");
    print_list(a);

    int actions = sort(&a, &b);

    printf("Après tri:\n");
    print_list(a);

    printf("Nombre d'actions: %d\n", actions);

    return 0;
}


