/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:55:27 by ysirkich          #+#    #+#             */
/*   Updated: 2024/07/08 17:14:00 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted_lst(t_stack *a)
{ //checks if the list is sorted in in ascending order
	t_stack	*top_node;

	if (!a)
		return (ft_print_error("Error while sorting"));
	top_node = ft_first_node(a);
	while (top_node->next)
	{
		if (top_node->value > top_node->next->value)
			return (0); //not sorted
		top_node = top_node->next;
	}
	return (1); //sorted
}

int	find_element_position(t_stack *stack, int minmax)
{ //the position of min or max element
	t_stack	*node;
	int	value;

	node = ft_first_node(stack);
	if (!node)
		return (ft_error("Error. something"));
	value = node->next;

	
}
int	find_element_value(t_stack *stack, int minmax)
{ //the value of min or max element

}