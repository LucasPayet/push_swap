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

void	ps_stack(t_stack *s1, t_stack *s2)
{
	t_node	*tmp[2];

	if (!s1->head)
		return ;
	tmp[0] = s1->head->next;
	tmp[1] = s2->head;
	s2->head = s1->head;
	s2->head->next = tmp[1];
	s1->head = tmp[0];
}

void	pa(t_stack *s1, )
