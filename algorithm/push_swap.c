/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:28:01 by ysirkich          #+#    #+#             */
/*   Updated: 2024/07/05 17:40:17 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(t_stack *a, t_stack *b, int size)
{
	//a = ft_first_node(a);
	if (size == 0)
		ft_print_error("something idk");
	if (ft_sorted_lst(a) == 1) //if stack is sorted already
		ft_print_error("The list is sorted already.");
	if (size == 2)
		ft_instructions(&a, &b, "sa");
	else if (size == 3)
		ft_three(a);
	else if (size ...)
	{
		/* code */
	}
	else
		ft_sort(a, b);
}
