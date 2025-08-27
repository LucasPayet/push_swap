/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:39:59 by lupayet           #+#    #+#             */
/*   Updated: 2025/08/27 15:48:13 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_s(t_stack *s)
{
	int		min;
	t_node	*node;

	min = s->head->index;
	node = s->head;
	while (node)
	{
		if (node->index < min)
			min = node->index;
		node = node->next;
	}
	return (min);
}

static void	three_sort(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	x = a->head->val;
	y = a->head->next->val;
	z = a->head->next->next->val;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}
	/*{
	int	i;
	int	j;
	int	k;

	i = a->head->val;
	j = a->head->next->val;
	k = a->head->next->next->val;
	if (i < j && j > k && k > i)
	{
		rra(a);
		sa(a);
	}
	else if (i > j && j < k && k > i)
		sa(a);
	else if (i < j && j > k && k < i)
		rra(a);
	else if (i > j && j < k && k < j)
		ra(a);
	else if (i > j && j > k && k < i)
	{
		sa(a);
		rra(a);
	}
}*/

void	push_min_b(t_stack *a, t_stack *b)
{
	int	min_pos;
	int	steps;

	while (a->size > 3)
	{
		min_pos = index_pos(min_s(a), a);
		if (min_pos <= a->size / 2)
		{
			while (min_pos--)
				ra(a);
		}
		else
		{
			steps = a->size - min_pos;
			while (steps--)
				rra(a);
		}
		pb(b, a);
	}
}

void	tsort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sa(a);
	else if (a->size == 3)
		three_sort(a);
	else if (a->size <= 5)
	{
		push_min_b(a, b);
		if (!is_sorted(a))
			three_sort(a);
		while (b->head)
			pa(a, b);
	}
}
