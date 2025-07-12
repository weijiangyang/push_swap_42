/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 11:23:27 by weiyang           #+#    #+#             */
/*   Updated: 2025/07/12 12:10:30 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int bring_max_to_top(t_list **list, int max_index)
{
        int size;
        int pos;
        t_list *current;
        int i;
        int count;

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

	
// chunk 
int sort(t_list **list_a, t_list **list_b)
{
        int     list_size = ft_list_size(*list_a);
        int	chunk_size = list_size / 5;
        int 	current_chunk = 1;
        int 	limit = chunk_size * current_chunk;
        int    	count_in_b = 0;
        int     count_actions;
	int	max;

        count_actions = 0;
        while (*list_a)
        {
                if ((*list_a)->index < limit)
                {
                        pb(list_a, list_b);
                        count_in_b++;
                        count_actions++;
                        if ((*list_b)->index < limit - (chunk_size / 2))
                        {
                                count_actions += rb(list_b); // pour mieux répartir
                        } 
                }
                else
                {
                        		count_actions += ra(list_a);
                }
		if (count_in_b >= chunk_size * current_chunk)  // passer au prochain chunk
                        current_chunk++;
                limit = chunk_size * current_chunk;
        }

        // ensuite : vider B en mettant le max au top
        while (*list_b)
        {
		max = get_max_index(*list_b);
                count_actions += bring_max_to_top(list_b, max);
                count_actions += pa(list_a, list_b);
                count_actions++;
        }
        return (count_actions);
}
/*
非常好的问题！你的排序函数实现了 push_swap 项目的一个分块版本，这是一个坚实的基础。现在你可以使用“贪婪”方法对其进行优化，尤其是针对将元素从 list_b 移动到 list_a 的阶段（最终阶段）。
🚀 目标：结合分块和贪婪策略

分块用于智能地分配 list_b 中的元素。

贪婪策略将最小化将每个元素从 list_b 移动到 list_a 所需的操作次数。

🔍 优化步骤（贪婪）
✅ 1. 替换最终阶段（第 207-213 行）

当前，你正在执行：

while (*list_b)
{
int max = get_max_index(*list_b);
count_actions += bring_max_to_top(list_b, max);
count_actions += pa(list_a, list_b);
count_actions++;
}

这很简单，但并非最优：每次只替换最大的元素，而不考虑总成本（a + b 所需的移动次数）。
💡 思路：选择 b 中向上移动成本最低的元素。

对于 list_b 中的每个元素，计算：

向上移动需要多少个操作（rb 或 rrb）

将其插入到 list_a 中的位置（计算 ra/rra 的成本）

可以组合多少个 rr/rrr。

选择成本最低的移动并应用它。
🧠 “贪婪”函数计划

以下是贪婪策略的框架：

t_move get_best_move(t_list *a, t_list *b);

int greedy_sort(t_list **a, t_list **b)
{
int count = 0;
while (*b)
{
t_move move = get_best_move(*a, *b);
count += execute_move(a, b, move);
}
return count;
}

get_best_move() 函数：

遍历 b 的所有元素

为每个元素找到 a 中的最佳位置

计算总成本 (cost_a, cost_b, + 潜在 rr/rrr)

保留总成本最小的那个

📦 t_move 结构体（示例）

typedef struct s_move
{
int cost_a;
int cost_b;
int total;
int direction_a; // 1 = ra, -1 = rra
int direction_b; // 1 = rb, -1 = rrb
t_list *target_b; // 要移动的元素
} t_move;

🔁 集成到你的排序函数中

你可以这样做：

将阶段 1 (list_a -> list_b) 保留在分块中

将阶段 2 (list_b -> list_a) 替换为 greedy_sort()

// ...
while (*list_a)
{
// 分块不变
}

// 替换如下：
// while (*list_b) { ... }

count_actions += greedy_sort(list_a, list_b);

🎯 结果

这种分块 + greedy 的组合可以让你：

减少不必要的旋转

结合 rr / rrr 动作

获得更高的动作得分*/
int	cal_pos_a(t_list *a, t_list *b)
{
	int	pos;
	int	size;
	int	pos_next_node;
	t_list	*tmp;
	int	min;
	int	cost;
	int	direction;

	min = INT_MAX;
	pos = 0;
	size = ft_list_size(a);
	tmp = a;
	tmp = a;
	while (tmp)
	{
		if (tmp->index > b->index && tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
	}
	if (min == INT_MAX)
	{
		tmp = a;
		while (tmp)
		{
			if(tmp->index < min)
				min = tmp -> index;
			tmp = tmp->next;
		}
	}
	tmp = a;
	while (tmp)
	{
		if (tmp->index == min)
			break;
		pos++;
		tmp = tmp->next;
	}
	if (pos < size / 2)
		return (pos);
	else
		return (-(size - pos));	
}
			

