/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:57:51 by ysirkich          #+#    #+#             */
/*   Updated: 2024/09/18 13:58:31 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int	if_unique(t_stack *node, int number);
static int	push_swap_atoi(char *str);

int	if_valid(char *str, t_stack *stack_a)
{
	int	number;
	
	if (!str || str[0] == '\0')
		return (-1);
	number = push_swap_atoi(str);
	if (number == -1)
		return (-1);
	if (if_unique(stack_a, number) == -1)
		return (-1);
	return (0);
}

static int	if_unique(t_stack *node, int number)
{
	while (node)
	{
		if (node->value == number)
			return (-1);
		node = node->next;
	}
	return (0);
}

static int	push_swap_atoi(char *str)
{
	long long	number;
	int			sign;
	int			index;

	number = 0;
	sign = 1;
	index = 0;
	if (str[index] == '-' || str[index] == '+')
	{
		if (!ft_isdigit(str[index + 1]))
    		return (-1);
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while (str[index])
	{
		if (!ft_isdigit(str[index]))
			return (-1);
		number = number * 10 + (str[index] - '0');
		if ((number * sign) > INT_MAX || (number * sign) < INT_MIN)
			return (-1);
		index++;
	}
	if (number == 0 && str[0] == '-')
        return (-1);
	return ((int)(number * sign));
}
