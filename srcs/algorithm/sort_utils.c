/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:55:27 by ysirkich          #+#    #+#             */
/*   Updated: 2024/09/18 13:09:30 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	sorted_lst(t_stack **stack_a)
{ //checks if the list is sorted in in ascending order
	t_stack	*top_node;

	if (!stack_a || !*stack_a)
		error("Error\n", stack_a);
	top_node = *stack_a;
	while (top_node->next)
	{
		if (top_node->value > top_node->next->value)
			return (0); //not sorted
		top_node = top_node->next;
	}
	return (1); //sorted
}

void	push_smallest(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		index;
	int		min_index;
	int		min_value;
	t_stack *current;
	int		ra_moves;
	int		rra_moves;

	current = *stack_a;
	index = 0;
	min_index = 0;
	min_value = INT_MAX;
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
	ra_moves = min_index;
	rra_moves = size - min_index;
	if (ra_moves <= rra_moves)
	{
		while (ra_moves-- > 0)
			instructions(stack_a, NULL, "ra");
	}
	else
	{
		while (rra_moves-- >  0)
			instructions(stack_a, NULL, "rra");
	}
	instructions(stack_a, stack_b, "pb");
}

void	assign_indices(t_stack **stack, int size)
{
	t_stack	*current_node;
	int *array;
	int	index;

	current_node = *stack;
	array = malloc(size * sizeof(int));//array to store values
	index = 0;
	while (current_node)
	{
		array[index++] = current_node->value;
		current_node = current_node->next;
	}
	quicksort(array, 0, size - 1);//sorting array
	current_node = *stack;
	while (current_node)
	{
		index = 0;
		while (index < size)
		{
			if (current_node->value == array[index])
			{
				current_node->index = index;
				break;
			}
			index++;
		}
		current_node = current_node->next;
	}
	free(array);
}