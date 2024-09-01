/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:28:01 by ysirkich          #+#    #+#             */
/*   Updated: 2024/09/01 17:23:17 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	three_sort(t_stack **stack_a);
static void	small_sort(t_stack **a, t_stack **b, int size);
static void	radix_sort(t_stack **stack_a, t_stack **stack_b, int size);

void	push_swap(t_stack **stack_a, t_stack **stack_b, int size)
{
	//a = ft_first_node(a);
	if (size == 0)
		error("Error. Size is 0\n", stack_a);
	if (sorted_lst(stack_a) == 1) //check if stack is sorted already
		error("Error. The list is sorted already.\n", stack_a);
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

	if (!stack_a || !*stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
		error("Error while sorting 3 elements.\n", stack_a);
	first = *stack_a;
	second = (*stack_a)->next;
	third = (*stack_a)->next->next;
	if (first->value > second->value && second->value > third->value)
	{
		instructions(stack_a, NULL, "sa");
		instructions(stack_a, NULL, "rra");
	}
	else if (first->value > third->value && third->value > second->value)
		instructions(stack_a, NULL, "ra");
	else if (second->value > first->value && first->value > third->value)
		instructions(stack_a, NULL, "sa");
	else if (second->value > third->value && third->value > first->value)
	{
		instructions(stack_a, NULL, "sa");
		instructions(stack_a, NULL, "ra");
	}
	else if (third->value > first->value && first->value > second->value)
		instructions(stack_a, NULL, "rra");
}

static void	small_sort(t_stack **a, t_stack **b, int size)
{// push 2 smallest number to stack b, sort the stack a, push back to stack a
	if (size == 4)
		push_smallest(a, b, 1);
	else if (size == 5)
		push_smallest(a, b, 2);
	three_sort(a);
	if (size == 5)
		instructions(a, b, "pa");
	instructions(a, b, "pa");
}

static void	radix_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	maximum_bits;
	int	maximum_number;
	int	index1;
	int	index2;

	maximum_bits = 0;
	maximum_number = size - 1;
	while ((maximum_number >> maximum_bits) != 0) //the number of bits needed to represent the largest number
		maximum_bits++;
	index1 = 0;
	while (index1 < maximum_bits)
	{
		index2 = 0;
		while (index2 < size)
		{
			if (((*stack_a)->index >> index1) & 1) //the current bit is 1
				instructions(stack_a, stack_b, "ra"); //stack_a upwards
			else
				instructions(stack_a, stack_b, "pb"); // push from stack_a to stack_b
			index2++;
		}
		while (*stack_b)
			instructions(stack_a, stack_b, "pa");
		index1++;
	}
}
