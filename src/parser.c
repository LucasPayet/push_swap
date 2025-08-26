/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 21:19:14 by lupayet           #+#    #+#             */
/*   Updated: 2025/08/20 11:17:53 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <limits.h>

void	indexer(t_stack *s)
{
	t_node	*curr;
	t_node	*min;
	int		i;

	i = 0;
	while (i < s->size)
	{
		curr = s->head;
		min = NULL;
		while (curr)
		{
			if (curr->index == -1)
			{
				if (!min || curr->val < min->val)
					min = curr;
			}
			curr = curr->next;
		}
		if (min)
			min->index = i;
		i++;
	}
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
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
		if (nb > INT_MAX || nb < INT_MIN)
			return (0);
		if (!add_end_stack(a, nb))
			return (0);
		i++;
	}
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
			free_split(split);
			return (0);
		}
		free_split(split);
		i++;
	}
	indexer(a);
	return (1);
}
