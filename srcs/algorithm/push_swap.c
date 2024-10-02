/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:28:01 by ysirkich          #+#    #+#             */
/*   Updated: 2024/10/02 21:39:10 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	three_sort(t_stack **stack_a);
static void	small_sort(t_stack **a, t_stack **b, int size);
static void	radix_sort(t_stack **stack_a, t_stack **stack_b, int size);

void	push_swap(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 0)
		error("Error\n", stack_a);
	if (sorted_lst(stack_a) == 1)
		error(NULL, stack_a);
	assign_indices(stack_a, size);
	if (size == 2)
		instructions(stack_a, stack_b, "sa");
	else if (size == 3)
		three_sort(stack_a);
	else if (size == 4 || size == 5)
		small_sort(stack_a, stack_b, size);
	else
		radix_sort(stack_a, stack_b, size);
}

static void	three_sort(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = *stack_a;
	second = (*stack_a)->next;
	third = (*stack_a)->next->next;
	if (first->value < second->value && second->value < third->value)
		return ;
	else if (first->value > second->value && second->value < third->value
		&& first->value < third->value)
		instructions(stack_a, NULL, "sa");
	else if (first->value < second->value && third->value < second->value
		&& third->value > first->value)
	{
		instructions(stack_a, NULL, "sa");
		instructions(stack_a, NULL, "ra");
	}
	else if (first->value > second->value && second->value > third->value)
	{
		instructions(stack_a, NULL, "sa");
		instructions(stack_a, NULL, "rra");
	}
	else if (first->value > second->value && third->value < first->value)
		instructions(stack_a, NULL, "ra");
	else
		instructions(stack_a, NULL, "rra");
}

static void	small_sort(t_stack **a, t_stack **b, int size)
{
	if (size == 4)
	{
		push_smallest(a, b, size);
		three_sort(a);
		instructions(a, b, "pa");
	}
	else if (size == 5)
	{
		push_smallest(a, b, size);
		push_smallest(a, b, size - 1);
		three_sort(a);
		instructions(a, b, "pa");
		instructions(a, b, "pa");
	}
}

static void	radix_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	maximum_bits;
	int	maximum_number;
	int	index1;
	int	index2;

	maximum_bits = 0;
	maximum_number = size - 1;
	while ((maximum_number >> maximum_bits))
		maximum_bits++;
	index1 = 0;
	while (index1 < maximum_bits)
	{
		index2 = 0;
		while (index2 < size)
		{
			if (((*stack_a)->index >> index1) & 1)
				instructions(stack_a, stack_b, "ra");
			else
				instructions(stack_a, stack_b, "pb");
			index2++;
		}
		while (*stack_b)
			instructions(stack_a, stack_b, "pa");
		index1++;
	}
}
