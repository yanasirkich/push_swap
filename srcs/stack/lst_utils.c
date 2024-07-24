/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich@student.hive.fi <ysirkich@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:24:57 by ysirkich@st       #+#    #+#             */
/*   Updated: 2024/07/08 11:52:15 by ysirkich@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void	ft_lstadd_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*lptr;

	if (!stack || !new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	lptr = *stack;
	while (lptr->next)
		lptr = lptr->next;
	lptr->next = new_node;
	new_node->prev = lptr;
}

t_stack	*ft_lstnew(int *value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void ft_lst_free(t_stack **stack)
{
	t_stack *lptr;

	while (*stack)
	{
		lptr = (*stack)->next;
		free(*stack);
		*stack = lptr;
	}
	*stack = NULL;
}