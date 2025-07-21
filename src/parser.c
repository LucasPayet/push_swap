/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 21:19:14 by lupayet           #+#    #+#             */
/*   Updated: 2025/07/21 17:09:50 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <limits.h>

void	indexer(t_stack *s)
{
	t_node	*n;
	t_node	*tmp;
	t_node	*li;
	int		i;

	i = 0;
	n = s->head;
	tmp = n;
	while (i < s->size)
	{
		while (n->next)
		{
			if (n->next->val < tmp->val)
				if (li && n->next->val > li->val)
				tmp = n->next;
			n = n->next;
		}
		tmp->index = i;
		li = tmp;
		tmp = s->head;
		while (tmp && tmp->index > -1)
			tmp = tmp->next;
		n = s->head;
		i++;
	}
}

int	stacker(t_stack *a, char **split)
{
	int		i;
	long	nb;

	i = 0;
	while (split[i])
	{
		if (!str_is_digits(split[i]))
			return (0);
		nb = ft_atoi(split[i]);
		free(split[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			return (0);
		if (!add_end_stack(a, nb))
			return (0);
		i++;
	}
	free(split);
	return (1);
}

int	parser(t_stack *a, int ac, char **av)
{
	int		i;
	char	**split;

	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		if (!split)
			return (0);
		if (!stacker(a, split))
		{
			free(split);
			return (0);
		}
		i++;
	}
	indexer(a);
	return (1);
}
