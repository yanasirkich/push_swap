/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:23:13 by ysirkich@st       #+#    #+#             */
/*   Updated: 2024/07/30 03:27:56 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void populate_lst(int count, t_stack **stack_a, char **args);
static void argument_check(int argc, char **argv, t_stack **stack_a);
int error(char *text);

int	main (int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;
	int	size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		error("Error: not enough arguments.");
	else
		argument_check(argc, argv, &stack_a);
	size = ft_lstsize(stack_a);
	if (size < 2)
	{
		ft_lst_free(&stack_a);
		return (error("Error: not enough elements to sort"));
	}
	push_swap(&stack_a, &stack_b, size); // sort the list
	ft_lst_free(&stack_a);
	ft_lst_free(&stack_b);
	return (0);
}

static void argument_check(int argc, char **argv, t_stack **stack_a)
{ //checks the arguments and populates stack a
	char **argument;
	int	count;

	argument = NULL;
	if (argc == 2) //single string
	{
		argument = ft_split(argv[1], ' ');
		count = 0;
		while (argument[count])
			count++;
		populate_lst(count, stack_a, argument);
		free(argument);
	}
	else //separate strings
		populate_lst(argc - 1, stack_a, argv + 1); // skip the program name
}

static void populate_lst(int count, t_stack **stack_a, char **args)
{ //converts the array of strings into a linked lis
	int index;
	t_stack	*new_node;

	index = 0;
	while (index < count)
	{
		new_node = ft_lstnew(ft_atoi(args[index]));
		ft_lstadd_back(stack_a, new_node);
		index++;
	}
}

int error(char *text)
{
	ft_putstr_fd(text, 1);
	return (-1);
}
