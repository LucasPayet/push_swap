/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:39:59 by lupayet           #+#    #+#             */
/*   Updated: 2025/08/21 15:12:22 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_s(t_stack *s)
{
	int	min;
    t_node	*node;

	max = s->head->index;
	node = s->head;
    while (node)
    {
        if (node->index < max)
            max = node->index;
        node = node->next;
    }
    return (min);
}

void	tsort(t_stack *a, t_stack *b)
{
if 

}
