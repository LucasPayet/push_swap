/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 11:22:50 by lupayet           #+#    #+#             */
/*   Updated: 2025/08/03 11:57:20 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ps_stack(t_stack *dest, t_stack *src)
{
	t_node	*tdest;
	t_node	*tsrc;

	if (!src->head)
		return ;
	tsrc = src->head->next;
	tdest = dest->head;
	dest->head = src->head;
	dest->head->next = tdest;
	src->head = tsrc;
}

void	pa(t_stack *a, t_stack *b)
{
	ft_putstr_fd("pa", 1);
	ps_stack(a, b);
}

void	pb(t_stack *b, t_stack *a)
{
	ft_putstr_fd("pb", 1);
	ps_stack(b, a);
}
