/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:53:25 by lupayet           #+#    #+#             */
/*   Updated: 2025/08/20 13:27:23 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	rt_stack(t_stack *s)
{
	t_node	*tmp;
	t_node	*i;

	if (!s->head || s->size <= 1)
		return ;
	tmp = s->head;
	s->head = s->head->next;
	i = s->head;
	while (i->next)
		i = i->next;
	i->next = tmp;
	i->next->next = NULL;
}

void	ra(t_stack *a)
{
	ft_putstr_fd("ra\n", 1);
	rt_stack(a);
}

void	rb(t_stack *b)
{
	ft_putstr_fd("rb\n", 1);
	rt_stack(b);
}

void	rr(t_stack *a, t_stack *b)
{
	ft_putstr_fd("rr\n", 1);
	rt_stack(a);
	rt_stack(b);
}
