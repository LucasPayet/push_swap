/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 21:33:02 by lupayet           #+#    #+#             */
/*   Updated: 2025/07/21 15:17:23 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdlib.h>

t_node	*new_node(int val)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->val = val;
	node->index = -1;
	node->next = NULL;
	return (node);
}

int	add_end_stack(t_stack *a, int val)
{
	t_node	*node;

	node = a->head;
	if (!node)
	{
		a->head = new_node(val);
		a->size += 1;
		return (1);
	}
	while (node->next)
	{
		if (node->val == val)
			return (0);
		node = node->next;
	}
	if (node->val == val)
		return (0);
	node->next = new_node(val);
	if (!node->next)
		return (0);
	a->size += 1;
	return (1);
}

int	clean_stack(t_stack *s)
{
	t_node *n;
	t_node *tmp;

	if (!s)
		return (0);
	n = s->head;
	s->head = NULL;
	while (n)
	{
		tmp = n->next;
		free(n);
		n = tmp;
	}
	return (1);
}
