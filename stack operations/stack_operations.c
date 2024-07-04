/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:22:54 by ysirkich          #+#    #+#             */
/*   Updated: 2024/07/04 19:07:28 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_swap(t_stack **stack)
{
	t_stack *first;
	t_stack *second;

	if (!(*stack)->next)
		ft_print_error("Error while swapping: stack only has 1 element.");
	if (!stack || !*stack)
		ft_print_error("Error while swapping: stack pointer or stack is empty.");
	//*stack = ft_first_node(*stack);
	first = *stack;
	second = first->next;
	if (!first || !second)
		ft_print_error("Error while swapping.");
	if (second->next)
		second->next->prev = first;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = first->prev;
	if (second->prev)
		second->prev->next = second;
	else
		*stack = second;
	return (0);
}

int	ft_push(t_stack **source_stack, t_stack **dest_stack)
{
	t_stack	*top_of_source;

	if (!source_stack || !dest_stack)
		ft_print_error("Error while pushing: NULL pointers");
	if (!*source_stack)
		ft_print_error("Error while pushing: Empty stack.");
	//*source_stack = ft_first_node(*source_stack);
	//*dest_stack = ft_first_node(*dest_stack);
	top_of_source = *source_stack;
	*source_stack = (*source_stack)->next;
	if (*source_stack)
		(*source_stack)->prev = NULL;
	top_of_source->next = *dest_stack;
	if (*dest_stack)
		(*dest_stack)->prev = top_of_source;
	*dest_stack = top_of_source;
	return (0);
}

int	ft_rotate(t_stack **stack, int rotate)
{
	t_stack	*first;
	t_stack	*last;
	
	if (!(*stack)->next)
		ft_print_error("Error while rotating: stack only has 1 element.");
	if (!stack || !*stack)
		ft_print_error("Error while rotating: stack pointer or stack is empty.");
	//first = ft_first_node(*stack);
	first = *stack;
	last = ft_last_node(*stack);
	if (!rotate) //forward rotation. the first node to the end
	{
		*stack = first->next;
		(*stack)->prev = NULL;
		first->next = NULL;
		last->next = first;
		first->prev = last;
	}
	else if (rotate) //reverse rotation. the last node to the front
	{
		*stack = last;
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = first;
		first->prev = last;
	}
	return (0);
}

int	ft_instructions(t_stack **a, t_stack **b, char *command) //something like ft_format in printf lol
{
	
}