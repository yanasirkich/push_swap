/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:55:27 by ysirkich          #+#    #+#             */
/*   Updated: 2024/07/05 17:36:08 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted_lst(t_stack *a)
{ //checks if the list is sorted in in ascending order
	t_stack	*top_node;

	if (!a)
		ft_print_error("Error while sorting");
	top_node = ft_first_node(a);
	while (top_node->next)
	{
		if (top_node->value > top_node->next->value)
			return (0); //not sorted
		top_node = top_node->next;
	}
	return (1); //sorted
}