/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utilsis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:25:50 by ysirkich          #+#    #+#             */
/*   Updated: 2024/07/08 13:41:01 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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