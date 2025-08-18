/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 15:53:25 by lupayet           #+#    #+#             */
/*   Updated: 2025/08/18 15:53:44 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "libft.h"

void	rt_stack(t_stack *s)
{
	t_stack	*tmp;
	t_stack	*i;

	if (!s->head || s-size <= 1)
		return ;
	tmp = s->head;
	s->head = s->head->next;
	i = s->head;
	while (i->next)
		i = i->next;
	i->next = tmp;
}

void	ra(t_stack *a)
{
	ft_putstr(ra);
	rt_stack(a);
}

void	rb(t_stack *b)
{
	ft_putstr(rb);
	rt_stack(b);
}

void	rr(t_stack *a, t_stack *b)
{
	ft_putstr(rr);
	rt_stack(a);
	rt_stack(b);
}
