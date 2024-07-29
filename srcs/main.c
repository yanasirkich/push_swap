/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:23:13 by ysirkich@st       #+#    #+#             */
/*   Updated: 2024/07/28 16:22:58 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void populate_lst(t_stack **stack_a, int count, char **args);
static void argument_check(int argc, char **argv, t_stack **stack_a);

int	main (int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;
	int	size;

	stack_a = NULL;
	stack_b = NULL;
	//size = 0;
	if (argc < 2)
		error("Error: not enough arguments.");
	else
		argument_check(argc, argv, &stack_a);
	size = ft_lstsize(stack_a);
	if (size < 2)
	{
		ft_lst_free(&stack_a);
		return (error("something")); //error handling
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
	count = 0;
	if (argc == 2) //single string
	{
		argument = ft_split(argv[1], ' ');
		while (argv[count])
			count++;
		populate_lst(stack_a, count, argument);
		free(argument);
	}
	else //separate strings
		populate_lst(count, argc - 1, argv + 1); // skip the program name
}

static void populate_lst(t_stack **stack_a, int count, char **args)
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
	ft_printf("%s", text);
	return (-1);
}