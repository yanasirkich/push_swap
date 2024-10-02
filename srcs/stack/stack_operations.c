/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:22:54 by ysirkich          #+#    #+#             */
/*   Updated: 2024/10/02 21:49:09 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		error("Error\n", stack);
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
	if (second->prev)
		second->prev->next = second;
	else
		*stack = second;
	return (0);
}

static int	push(t_stack **source_stack, t_stack **dest_stack)
{
	t_stack	*top_of_source;

	if (!source_stack || !dest_stack || !*source_stack)
		error("Error\n", source_stack);
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

static int	rotate(t_stack **stack, int rotate)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		error("Error\n", stack);
	first = *stack;
	last = ft_last_node(*stack);
	if (!rotate)
	{
		*stack = first->next;
		(*stack)->prev = NULL;
		first->next = NULL;
		last->next = first;
		first->prev = last;
	}
	else if (rotate)
	{
		last->prev->next = NULL;
		last->prev = NULL;
		last->next = first;
		first->prev = last;
		*stack = last;
	}
	return (0);
}

int	execute_command(t_stack **stack_a, t_stack **stack_b, char *command)
{
	if (ft_strcmp(command, "sa") == 0)
		return (swap(stack_a));
	else if (ft_strcmp(command, "sb") == 0)
		return (swap(stack_b));
	else if (ft_strcmp(command, "ss") == 0)
		return (swap(stack_a) && swap(stack_b));
	else if (ft_strcmp(command, "pa") == 0)
		return (push(stack_b, stack_a));
	else if (ft_strcmp(command, "pb") == 0)
		return (push(stack_a, stack_b));
	else if (ft_strcmp(command, "ra") == 0)
		return (rotate(stack_a, 0));
	else if (ft_strcmp(command, "rb") == 0)
		return (rotate(stack_b, 0));
	else if (ft_strcmp(command, "rr") == 0)
		return (rotate(stack_a, 0) && rotate(stack_b, 0));
	else if (ft_strcmp(command, "rra") == 0)
		return (rotate(stack_a, 1));
	else if (ft_strcmp(command, "rrb") == 0)
		return (rotate(stack_b, 1));
	else if (ft_strcmp(command, "rrr") == 0)
		return (rotate(stack_a, 1) && rotate(stack_b, 1));
	else
		error("Error\n", stack_a);
	return (0);
}

int	instructions(t_stack **stack_a, t_stack **stack_b, char *command)
{
	if (valid_instructions(stack_a, stack_b, command) == -1)
		error("Error\n", stack_a);
	ft_putstr_fd(command, 1);
	ft_putstr_fd("\n", 1);
	if (execute_command(stack_a, stack_b, command) == -1)
		error("Error\n", stack_a);
	return (0);
}
