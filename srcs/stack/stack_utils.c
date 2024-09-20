/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:25:50 by ysirkich          #+#    #+#             */
/*   Updated: 2024/09/20 16:31:42 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <stdio.h>

t_stack *ft_first_node(t_stack *node)
{
	if (!node)
		return (NULL);
	while (node->prev)
		node = node->prev;
	return (node);
}

t_stack *ft_last_node(t_stack *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

int valid_instructions(t_stack **stack_a, t_stack **stack_b, char *command)
{
	//printf("Checking command: %s\n", command);
	//printf("Stack A: %p, Stack B: %p\n", (void *)stack_a, (void *)stack_b);

	if (!command)
		return (-1);
	 if (!(*stack_a))
	 {
		if ((ft_strcmp(command, "ra") == 0 || ft_strcmp(command, "rra") == 0 || ft_strcmp(command, "rr") == 0) && !(*stack_a))
			return (-1);
		if (ft_strcmp(command, "pb") == 0 && !(*stack_a))
			return (-1);
	 }
	if (ft_strcmp(command, "pa") == 0 && !(*stack_b))
		return (-1);
	else
		return (0);
}