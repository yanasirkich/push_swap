/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:55:27 by ysirkich          #+#    #+#             */
/*   Updated: 2024/07/04 19:05:01 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorted_lst(t_stack *a)
{
	t_stack	top_node;

	if (!a)
		ft_print_error("Error while sorting");
	top_node = ft_first_node(a);
	
}