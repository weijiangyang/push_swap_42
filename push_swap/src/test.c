在 push_swap 中将分块与贪婪策略相结合是一个可以大幅减少操作的好主意。以下是对其含义及其实现方法的清晰解释。
🧠 目标：“分块贪婪策略”
📌 上下文：

您已经有一个分块排序：根据元素的索引，分批（例如，5 个分块）将元素发送到 B。

现在，您需要优化在每个分块中选择和移动元素的方式：

👉 不是按顺序移动，而是找到最接近的元素进行推送（顶部或底部）。
🔁 新策略：贪婪推送到 B
🔎 步骤 1：找到当前分块中距离顶部或底部最近的元素。
int find_closest_in_chunk(t_list *a, int min, int max)
{
int top_moves = 0;
int bottom_moves = 0;
t_list *tmp;

// 从顶部开始
tmp = a;
while (tmp && !(tmp->index >= min && tmp->index < max)) {
top_moves++;
tmp = tmp->next;
}

// 从底部开始
tmp = a;
int len = ft_list_size(a);
while (tmp->next)
tmp = tmp->next;
while (tmp && !(tmp->index >= min && tmp->index < max)) {
bottom_moves++;
tmp = tmp->prev;
}

return (top_moves <= bottom_moves) ? 1: -1; // 1 = 顶部，-1 = 底部
}
⚙️ 步骤 2：将最近的元素向上移动，然后执行 pb
if (find_closest_in_chunk(*a, min, max) == 1)
while (!((*a)->index >= min && (*a)->index < max))
count += ra(a);
else
while (!((*a)->index >= min && (*a)->index < max))
count += rra(a);

count += pb(b, a);
🎯 步骤 3：重复，直到所有块都清空
💡 额外奖励：针对 b 侧的优化

在 pb 操作期间，您还可以在 b 侧使用贪婪插入策略：

如果索引较小，我们将其推送并执行 rb（将其保持在底部）。

如果索引较大，我们直接推送它（它将位于顶部，靠近最终的 pb）。
int sort(t_list **a, t_list **b)
{
int size = ft_list_size(*a);
int chunk_size = size / 5;
int count = 0;

for (int c = 0; c < 5; c++) {
int min = c * chunk_size;
int max = (c + 1) * chunk_size;

int pushed = 0;
while (pushed < chunk_size && !is_empty(*a)) {
if (find_closest_in_chunk(*a, min, max) == 1)
while (!((*a)->index >= min && (*a)->index < max))
count += ra(a);
else
while (!((*a)->index >= min && (*a)->index < max))
count += rra(a);

count += pb(b, a);
pushed++;
}
}

// 最后阶段：清空 B（例如，始终返回最大值）
while (*b) {
int max = get_max_index(*b);
count += bring_max_to_top(b, max);
count += pa(a, b);
}
return count;
}
✅ 预期结果：

✅ 减少不必要的 ra</i>s

✅ 减少错位的 pb</i>s

✅ b 的结构更好地为最终的 pa 做好准备</i>
