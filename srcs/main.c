/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:23:13 by ysirkich@st       #+#    #+#             */
/*   Updated: 2024/09/20 16:48:39 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	populate_lst(int count, t_stack **stack_a, char **args);
static void	argument_check(int argc, char **argv, t_stack **stack_a);
int			error(char *text, t_stack **stack_a);

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		error("Error\n", &stack_a);
	else
		argument_check(argc, argv, &stack_a);
	size = ft_lstsize(stack_a);
	if (size < 2)
		error("Error\n", &stack_a);
	push_swap(&stack_a, &stack_b, size);
	ft_lst_free(&stack_a);
	ft_lst_free(&stack_b);
	return (0);
}

static void	argument_check(int argc, char **argv, t_stack **stack_a)
{
	char	**argument;
	int		count;

	argument = NULL;
	if (argc == 2)
	{
		argument = ft_split(argv[1], ' ');
		if (!argument)
			error("Error\n", stack_a);
		count = 0;
		while (argument[count])
			count++;
		populate_lst(count, stack_a, argument);
		free(argument);
	}
	else
		populate_lst(argc - 1, stack_a, argv + 1);
}

static void	populate_lst(int count, t_stack **stack_a, char **args)
{
	int		index;
	t_stack	*new_node;

	index = 0;
	while (index < count)
	{
		if (if_valid(args[index], *stack_a) == -1)
			error("Error\n", stack_a);
		new_node = ft_lstnew(ft_atoi(args[index]));
		if (!new_node)
			error("Error\n", stack_a);
		ft_lstadd_back(stack_a, new_node);
		index++;
	}
}

int	error(char *text, t_stack **stack_a)
{
	if (stack_a && *stack_a)
	{
		ft_putstr_fd(text, 2);
		ft_lst_free(stack_a);
		*stack_a = NULL;
	}
	else
		ft_putstr_fd(text, 2);
	exit(EXIT_FAILURE);
}
