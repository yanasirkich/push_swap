/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:28:01 by ysirkich          #+#    #+#             */
/*   Updated: 2024/07/30 03:32:31 by ysirkich         ###   ########.fr       */
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
		error("something idk");
	if (sorted_lst(stack_a)) //check if stack is sorted already
		error("Error. The list is sorted already.");
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
		error("Error. something idk");
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
	if (first->value > third->value && third->value > second->value)
		instructions(stack_a, NULL, "ra");
	//3. second > first > third
	if (second->value > first->value && first->value > third->value)
		instructions(stack_a, NULL, "sa");
	//4. second > third > first
	if (second->value > third->value && third->value > first->value)
	{
		instructions(stack_a, NULL, "sa");
		instructions(stack_a, NULL, "ra");
	}
	//5. third > first > second
	if (third->value > first->value && first->value > second->value)
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
	int	length;

	length = size;
	while (length > 3)
	{
		push_smallest(stack_a, stack_b, length);
		length--;
	}
	three_sort(stack_a);
	while(*stack_b)
		instructions(stack_a, stack_b, "pa");
	if ((*stack_a)->value > (*stack_a)->next->value)
		instructions(stack_a, stack_b, "sa");
}