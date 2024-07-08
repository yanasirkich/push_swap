/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich@student.hive.fi <ysirkich@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:23:13 by ysirkich@st       #+#    #+#             */
/*   Updated: 2024/07/08 11:50:03 by ysirkich@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main (int argc, char **argv)
{
	t_stack	*a;
	t_stack *b;
	int	size;

	a = NULL;
	b = NULL;
	//size = 0;
	if (argc < 2)
		ft_print_error("Error: not enough arguments.");
	else
		ft_argument_check(argc, argv, &a);
	size = ft_lstsize(a);
	if (size < 2)
	{
		ft_lst_free(&a);
		return (ft_print_error("something")); //error handling
	}
	ft_push_swap(&a, &b, size); // sort the list
	ft_lst_free(&a);
	ft_lst_free(&b);
	return (0);
}

void ft_argument_check(int argc, char **argv, t_stack **a)
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
		ft_populate_lst(a, count, argument);
		free(argument);
	}
	else //separate strings
		ft_populate_lst(count, argc - 1, argv + 1); // skip the program name
}

void ft_populate_lst(t_stack **a, int count, char **args)
{ //converts the array of strings into a linked lis
	int i;
	t_stack	*new_node;

	i = 0;
	while (i < count)
	{
		new_node = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(a, new_node);
		i++;
	}
}