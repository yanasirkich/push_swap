/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:28:01 by ysirkich          #+#    #+#             */
/*   Updated: 2024/08/21 16:24:36 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
static void	three_sort(t_stack **stack_a);
static void	small_sort(t_stack **a, t_stack **b, int size);
static void	sort(t_stack **stack_a, t_stack **stack_b, int size);

void	push_swap(t_stack **stack_a, t_stack **stack_b, int size)
{
	//a = ft_first_node(a);
	if (size == 0)
		error("Error. Size is 0\n", stack_a);
	if (sorted_lst(stack_a) == 1) //check if stack is sorted already
		error("Error. The list is sorted already.\n", stack_a);
	assign_indices(*stack_a, size);
	if (size == 2)
		instructions(stack_a, stack_b, "sa");
	else if (size == 3)
		three_sort(stack_a);
	else if (size == 4 || size == 5)
		small_sort(stack_a, stack_b, size);
	else
		sort(stack_a, stack_b, size);
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
	//1. first > second > third
	if (first->value > second->value && second->value > third->value)
	{
		instructions(stack_a, NULL, "sa");
		instructions(stack_a, NULL, "rra");
	}
	//2. first > third > second
	else if (first->value > third->value && third->value > second->value)
		instructions(stack_a, NULL, "ra");
	//3. second > first > third
	else if (second->value > first->value && first->value > third->value)
		instructions(stack_a, NULL, "sa");
	//4. second > third > first
	else if (second->value > third->value && third->value > first->value)
	{
		instructions(stack_a, NULL, "sa");
		instructions(stack_a, NULL, "ra");
	}
	//5. third > first > second
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

static void	sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	maximum_bits;
	int	maximum_number;
	int	index1;
	int	index2;
}