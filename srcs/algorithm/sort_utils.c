/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:55:27 by ysirkich          #+#    #+#             */
/*   Updated: 2024/09/20 19:43:38 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_value(t_stack *stack);
static int	find_min_index(t_stack *stack, int min_value);

int	sorted_lst(t_stack **stack_a)
{
	t_stack	*top_node;

	if (!stack_a || !*stack_a)
		error("Error\n", stack_a);
	top_node = *stack_a;
	while (top_node->next)
	{
		if (top_node->value > top_node->next->value)
			return (0);
		top_node = top_node->next;
	}
	return (1);
}

void	push_smallest(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		min_index;
	int		min_value;
	int		ra_moves;
	int		rra_moves;

	min_value = find_min_value(*stack_a);
	min_index = find_min_index(*stack_a, min_value);
	ra_moves = min_index;
	rra_moves = size - min_index;
	if (ra_moves <= rra_moves)
	{
		while (ra_moves-- > 0)
			instructions(stack_a, NULL, "ra");
	}
	else
	{
		while (rra_moves-- > 0)
			instructions(stack_a, NULL, "rra");
	}
	instructions(stack_a, stack_b, "pb");
}

static int	find_min_value(t_stack *stack)
{
	int		min_value;
	t_stack	*current;

	min_value = INT_MAX;
	current = stack;
	while (current)
	{
		if (current->value < min_value)
			min_value = current->value;
		current = current->next;
	}
	return (min_value);
}

static int	find_min_index(t_stack *stack, int min_value)
{
	int		index;
	int		min_index;
	t_stack	*current;

	index = 0;
	min_index = -1;
	current = stack;
	while (current)
	{
		if (current->value == min_value)
		{
			min_index = index;
			break ;
		}
		current = current->next;
		index++;
	}
	return (min_index);
}

void	assign_indices(t_stack **stack, int size)
{
	t_stack	*current_node;
	int		*array;
	int		index;
	int		node;

	current_node = *stack;
	array = malloc(size * sizeof(int));
	index = 0;
	while (current_node)
	{
		array[index++] = current_node->value;
		current_node = current_node->next;
	}
	quicksort(array, 0, size - 1);
	current_node = *stack;
	while (current_node)
	{
		node = 0;
		while (node < size && current_node->value != array[node])
			node++;
		current_node->index = node;
		current_node = current_node->next;
	}
	free(array);
}
