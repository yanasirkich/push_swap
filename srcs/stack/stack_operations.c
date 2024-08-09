/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:22:54 by ysirkich          #+#    #+#             */
/*   Updated: 2024/07/30 17:57:19 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	swap(t_stack **stack)
{
	t_stack *first;
	t_stack *second;

	if (!(*stack)->next)
		error("Error while swapping: stack only has 1 element.");
	if (!stack || !*stack)
		error("Error while swapping: stack pointer or stack is empty.");
	//*stack = ft_first_node(*stack);
	first = *stack;
	second = first->next;
	if (!first || !second)
		error("Error while swapping.");
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

static int	push(t_stack **source_stack, t_stack **dest_stack)
{
	t_stack	*top_of_source;

	if (!source_stack || !dest_stack)
		error("Error while pushing: NULL pointers");
	if (!*source_stack)
		error("Error while pushing: Empty stack.");
	
	top_of_source = *source_stack;
	*source_stack = (*source_stack)->next;

	//*source_stack = ft_first_node(*source_stack);
	//*dest_stack = ft_first_node(*dest_stack);
	
	if (*source_stack)
		(*source_stack)->prev = NULL;
	top_of_source->next = *dest_stack;
	if (*dest_stack)
		(*dest_stack)->prev = top_of_source;
	*dest_stack = top_of_source;
	return (0);
}

static int	rotate(t_stack **stack, int rotate)
{
	t_stack	*first;
	t_stack	*last;
	
	if (!(*stack)->next)
		error("Error while rotating: stack only has 1 element.");
	if (!stack || !*stack)
		error("Error while rotating: stack pointer or stack is empty.");
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

int	instructions(t_stack **stack_a, t_stack **stack_b, char *command) //something like ft_format in printf lol
{
	ft_putstr_fd(command, 1);
	ft_putstr_fd("\n", 1);
	if (ft_strcmp(command, "sa") == 0)
		return (swap(stack_a));
	if (ft_strcmp(command, "sb") == 0)
		return (swap(stack_b));
	if (ft_strcmp(command, "ss") == 0)
		return (swap(stack_a) && swap(stack_b));
	if (ft_strcmp(command, "pa") == 0)
		return (push(stack_b, stack_a));
	if (ft_strcmp(command, "pb") == 0)
		return (push(stack_a, stack_b));
	if (ft_strcmp(command, "ra") == 0)
		return (rotate(stack_a, 0));
	if (ft_strcmp(command, "rb") == 0)
		return (rotate(stack_b, 0));
	if (ft_strcmp(command, "rr") == 0)
		return (rotate(stack_a, 0) && rotate(stack_b, 0));
	if (ft_strcmp(command, "rra"))
		return (rotate(stack_a, 1));
	if (ft_strcmp(command, "rrb"))
		return (rotate(stack_b, 1));
	if (ft_strcmp(command, "rrr"))
		return (rotate(stack_b, 1) && rotate(stack_b, 1));
	return (0);
}

void	execute(t_stack **stack_a, t_stack **stack_b, char *command, int times)
{ //do the same command multiple times
	 while (times > 0)
	 {
		if (!instructions(stack_a, stack_b, command))
			error("Error. Failed to execute command.");
	 }
	times--;

}