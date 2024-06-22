/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich@student.hive.fi <ysirkich@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:23:13 by ysirkich@st       #+#    #+#             */
/*   Updated: 2024/06/22 16:09:54 by ysirkich@st      ###   ########.fr       */
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
	size = 0;
	if (argc < 2)
		return (0); //maybe error handling
	else
		ft_argument_check(argc, argv, &a);
	size = ft_lstsize(a);
	if (size == 2)
		return (0);
	ft_lst_split(&a, &b, size);
	ft_lst_free(&a);
	ft_lst_free(&b);
}

void ft_argument_check(int argc, char **argv, t_stack **a)
{
	char **argument;
	int	count;

	argument = NULL;
	count = 0;
	if (argc == 2)
	{
		argument = ft_split(argv[1], ' ');
		while (argv[count])
			count++;
		ft_print_lst(count, argument, a)
		free (argument);
	}
	else
		ft_print_lst(count, argc - 1, argv + 1);
}