/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:55:27 by ysirkich          #+#    #+#             */
/*   Updated: 2024/07/22 17:18:05 by ysirkich         ###   ########.fr       */
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

void	ft_push_smallest(t_stack **a, t_stack **b, int size)
{
	int	index;
	int	min_index;
	int	min_value;
	t_stack *current;

	current = *a;
	index = 0;
	min_index = 0;
	while (current)
	{ //the index of the smallest element in the stack
		if (current->value < min_value)
		{
			min_value = current->value;
			min_index = index;
		}
		current = current->next;
		index++;
	}
	//the smallest element to the top and push to stack
		if (min_index <= size / 2)
		{
			while (min_index-- > 0)
				ft_instructions(a, b, "ra");
		}
		else
			{
				while(min_index++ < size)
					ft_instructions(a, b, "rra");
			}
			ft_instructioms(a, b, "pb");
}
