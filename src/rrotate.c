/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:12:13 by lupayet           #+#    #+#             */
/*   Updated: 2025/08/20 13:27:42 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "libft.h"

void	rrt_stack(t_stack *s)
{
	t_node	*tmp;
	t_node	*nlast;
	t_node	*i;

	if (!s->head || s->size <= 1)
		return ;
	tmp = s->head;
	i = s->head;
	while (i->next)
	{
		if (!i->next->next)
			nlast = i;
		i = i->next;
	}
	s->head = i;
	s->head->next = tmp;
	nlast->next = NULL;
}

void	rra(t_stack *a)
{
	ft_putstr_fd("rra\n", 1);
	rrt_stack(a);
}

void	rrb(t_stack *b)
{
	ft_putstr_fd("rrb\n", 1);
	rrt_stack(b);
}

void	rrr(t_stack *a, t_stack *b)
{
	ft_putstr_fd("rrr\n", 1);
	rrt_stack(a);
	rrt_stack(b);
}
