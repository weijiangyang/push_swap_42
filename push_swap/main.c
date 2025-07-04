/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 13:34:02 by weiyang           #+#    #+#             */
/*   Updated: 2025/07/04 15:20:22 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list  *list;
    t_list  *list_b;
    int		count;

    list = parse_list(argc, argv);  // <- parse_list doit retourner un t_list *
    list_b = NULL;

    count = sort(&list, &list_b);  // <- on passe les adresses car sort attend t_list **

    while (list)
    {
        printf("%d\n", list->value);
        list = list->next;
    }
    printf("il faut %d fois d'oeperations", count);
    return (0);
}

