/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:23:13 by ysirkich@st       #+#    #+#             */
/*   Updated: 2024/08/12 03:19:54 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void populate_lst(int count, t_stack **stack_a, char **args);
static void argument_check(int argc, char **argv, t_stack **stack_a);
int error(char *text, t_stack *stack_a);

int	main (int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;
	int	size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		error("Error: not enough arguments\n", stack_a);
	else
		argument_check(argc, argv, &stack_a);
	size = ft_lstsize(stack_a);
	if (size < 2)
		error("Error: not enough elements to sort\n", stack_a);
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
		if (!argument)
			error("Error. ft_split failed.\n", stack_a);
		count = 0;
		while (argument[count])
			count++;
		populate_lst(count, stack_a, argument);
		free_argument();
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
		if (if_valid(stack_a, args[index]) == -1)
			error("Error. The arguments are not valid.\n", stack_a);
		new_node = ft_lstnew(ft_atoi(args[index]));
		if (!new_node)
			error("Error. ft_lstnew failed.\n", stack_a);
		ft_lstadd_back(stack_a, new_node);
		index++;
	}
}

int error(char *text, t_stack *stack_a)
{
	ft_putstr_fd(text, 1);
	ft_lst_free(stack_a);
	return (EXIT_FAILURE); 
}
