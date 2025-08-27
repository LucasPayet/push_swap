/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ksort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:47:49 by lupayet           #+#    #+#             */
/*   Updated: 2025/08/27 13:50:56 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_s(t_stack *s)
{
	int		max;
	t_node	*node;

	max = s->head->index;
	node = s->head;
	while (node)
	{
		if (node->index > max)
			max = node->index;
		node = node->next;
	}
	return (max);
}

int	index_pos(int index, t_stack *s)
{
	t_node	*node;
	int		position;

	node = s->head;
	position = 0;
	while (node)
	{
		if (node->index == index)
			return (position);
		node = node->next;
		position++;
	}
	return (-1);
}

void	k_distribution(t_stack *a, t_stack *b)
{
	int	delta;
	int	threshold;
	int	td;

	delta = a->size / 20 + 7;
	threshold = 0;
	while (a->head)
	{
		td = threshold + delta;
		if (a->head->index <= td)
		{
			pb(b, a);
			if (b->head->index <= threshold)
				rb(b);
			threshold++;
		}
		else
			ra(a);
	}
}

void	k_reintegration(t_stack *a, t_stack *b)
{
	int	max_index;
	int	pos;

	while (b->head)
	{
		max_index = max_s(b);
		pos = index_pos(max_index, b);
		if (pos <= b->size / 2)
			while (b->head->index != max_index)
				rb(b);
		else
			while (b->head->index != max_index)
				rrb(b);
		pa(a, b);
	}
}

void	k_sort(t_stack *a, t_stack *b)
{
	k_distribution(a, b);
	k_reintegration(a, b);
}
