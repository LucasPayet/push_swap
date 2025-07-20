/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lupayet <lupayet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 20:33:15 by lupayet           #+#    #+#             */
/*   Updated: 2025/07/20 00:33:09 by lupayet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node
{
	int				val;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	int		size;
}	t_stack;

int		parser(t_stack *a, int ac, char **av);
t_node	*new_node(int val);
int		add_end_stack(t_stack *a, int val);
int		clean_stack(t_stack *s);
int		str_is_digits(char *str);

#endif
