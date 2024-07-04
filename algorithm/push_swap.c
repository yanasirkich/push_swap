/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:28:01 by ysirkich          #+#    #+#             */
/*   Updated: 2024/07/04 19:06:49 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(t_stack *a, t_stack *b, int size)
{
	//a = ft_first_node(a);
	if (ft_sorted_lst(a) == 1) //if stack is sorted already
		ft_print_error("The list is sorted already.");
	if (size == 2)
		return(ft_instructions(&a, &b, "sa"));
}
