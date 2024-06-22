/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich@student.hive.fi <ysirkich@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:23:13 by ysirkich@st       #+#    #+#             */
/*   Updated: 2024/06/22 13:44:33 by ysirkich@st      ###   ########.fr       */
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
		//return something;
	else ft_argument_check(argc, argv)
	size = ft_lstsize(a);
	if (size == 2)
		//return null maybe idk
	ft_lst_split(&a, &b, size);
	ft_lst_free(&a);
	ft_lst_free(&b);
}

int ft_argument_check(int argc, char **argv)
{
	char **argument;

	
}