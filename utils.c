/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:40:59 by ysirkich@st       #+#    #+#             */
/*   Updated: 2024/07/04 18:31:20 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int ft_print_error(char *text)
{
	int i;
	while(text[i])
	{
		write(1, &i, 1);
		i++;
	}
	return (-1);
}