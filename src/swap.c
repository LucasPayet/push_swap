/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:14:23 by lupayet           #+#    #+#             */
/*   Updated: 2025/07/21 14:35:49 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	s_stack(t_stack *s)
{
	t_node	*tmp;

	if (s->size <=1)
		return ;
	tmp = s->head;
	s->head = tmp->next;
	tmp->next = s->head->next;
	s->head->next = tmp;
}

void	sa(t_stack *a)
{
	s_stack(a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *b)
{
	s_stack(b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *a, t_stack *b)
{
	s_stack(a);
	s_stack(b);
	ft_putstr_fd("ss\n", 1);
}
