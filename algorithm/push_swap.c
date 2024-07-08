/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:28:01 by ysirkich          #+#    #+#             */
/*   Updated: 2024/07/08 15:32:23 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(t_stack *a, t_stack *b, int size)
{
	//a = ft_first_node(a);
	if (size == 0)
		ft_print_error("something idk");
	if (ft_sorted_lst(a)) //check if stack is sorted already
		return (ft_print_error("Error. The list is sorted already."));
	if (size == 2)
		ft_instructions(&a, &b, "sa");
	else if (size == 3)
		ft_three_sort(a);
	else if (size == 4 || size == 5)
		ft_small_sort(a, b, size);
	else
		ft_sort(a, b);
}

void	ft_three_sort(t_stack **a)
{ 
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		ft_print_error("Error. something idk");
	first = *a;
	second = (*a)->next;
	third = (*a)->next->next;
	//1. first > second > third
	if (first->value > second->value && second->value > third->value)
	{
		ft_instructions(a, NULL, "sa");
		ft_instructions(a, NULL, "rra");
	}
	//2. first > third > second
	if (first->value > third->value && third->value > second->value)
		ft_instructions(a, NULL, "ra");
	//3. second > first > third
	if (second->value > first->value && first->value > third->value)
		ft_instructions(a, NULL, "sa");
	//4. second > third > first
	if (second->value > third->value && third->value > first->value)
	{
		ft_instructions(a, NULL, "sa");
		ft_instructions(a, NULL, "ra");

	}
	//5. third > first > second
	if (third->value > first->value && first->value > second->value)
		ft_instructions(a, NULL, "rra");
}

void	ft_small_sort(t_stack *a, t_stack *b, int size)
{// push 2 smallest number to stack b, sort the stack a, push back to stack a
	while (size > 3)
	{
		// adjust position of min/max elements in stack a
		//push top element from stack a to stack b
	}
	ft_three_sort(a);
	ft_execute(&a, &b, "pa", size - 3);	
}

void	ft_sort(t_stack *a, t_stack *b)
{
	
}