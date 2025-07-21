/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 20:30:13 by lupayet           #+#    #+#             */
/*   Updated: 2025/07/21 15:00:59 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>

void	print_stack(t_stack *s)
{
	t_node *n;

	ft_printf("Print_stack\n\n");
	if (!s)
		return ;
	n = s->head;
	while (n)
	{
		ft_printf("val = %d, index = %d\n", n->val, n->index);
		if (n->next)
			n = n->next;
		else
			return ;
	}
}

int	main(int ac, char **av)
{
	t_stack	a;

	a.head = NULL;
	a.size = 0;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	if (!parser(&a, ac, av))
	{
		write(2, "Error\n", 6);
		print_stack(&a);
		clean_stack(&a);
		return (1);
	}
	print_stack(&a);
	sa(&a);
	print_stack(&a);
	clean_stack(&a);
}
