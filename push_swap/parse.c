/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:14:11 by weiyang           #+#    #+#             */
/*   Updated: 2025/07/04 14:45:32 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//creation du nouveau noeud

t_list *new_node(int value)
{
	t_list	*new_node;

	new_node = malloc (sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->next = NULL;
	return (new_node);
}

long	ft_atoi(char *s)
{
	long	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*s == ' ' || *s == '\t')
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + (*s - '0');
		s++;
	}
	return (sign * res);
}

int     is_valid_int(char *str)
{
        long    result;

        result = ft_atoi(str);
        if (result > INT_MAX || result < INT_MIN)
                return (0);
        else
                return (1);
}

// duplicate

int	has_duplicate(t_list *list)
{
	int	tmp;
	t_list	*cpy;
	
	while (list)
	{
		cpy = list->next;
		tmp = list->value;
		while (cpy)
		{
			if(cpy->value == tmp)
				return (1);
			cpy = cpy->next;
		}
		list = list->next;
	}
	return (0);
} 
		

void assign_indexes(t_list *lst)
{
        t_list  *tmp1;
        t_list  *tmp2;
        int     rank;

        tmp1 = lst;
	if (!lst)
	{
    		printf("assign_indexes: list is NULL\n");
    		return;
	}
        while (tmp1)
        {
                rank = 0;
                tmp2 = lst;
                while (tmp2)
                {
                        if(tmp1->value > tmp2->value)
                                rank++;
                        tmp2 = tmp2->next;
                }
                tmp1->index = rank;
                tmp1 = tmp1->next;
        }
}
	

t_list	*parse_list(int argc, char **argv)
{
	int	i;

	t_list	*list;
	t_list	*last;
	t_list	*new;

	list = NULL;
	last = NULL;
	i = 1;
	while (i < argc)
	{
		if (!is_valid_int(argv[i]))
		{
			printf("Error: invalid integer");
			return (NULL);
		}
		new = new_node(ft_atoi(argv[i]));
		if (!new)
			return (NULL);
		if(!list)
		{
			list = new;
			last = new;
		}
		else
		{
			last -> next = new;
			last = new;
		}
		i++;
	}
	if (has_duplicate(list))
	{
		printf("Error:duplicated detected");
		return (NULL);
	}
	assign_indexes(list);
	return (list);
}

