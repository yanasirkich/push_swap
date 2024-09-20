/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:57:40 by ysirkich          #+#    #+#             */
/*   Updated: 2024/09/20 17:02:02 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		partition(int *array, int low, int high);
static void		swap(int *a, int *b);

void	quicksort(int *array, int low, int high)
{
	int	pivot;

	if (high > low)
	{
		pivot = partition(array, low, high);
		quicksort(array, low, pivot - 1);
		quicksort(array, pivot + 1, high);
	}
}

static int	partition(int *array, int low, int high)
{
	int	pivot;
	int	index;
	int	current_element;

	pivot = array[high];
	index = low - 1;
	current_element = low;
	while (current_element < high)
	{
		if (array[current_element] <= pivot)
		{
			index++;
			swap(&array[index], &array[current_element]);
		}
		current_element++;
	}
	swap(&array[index + 1], &array[high]);
	return (index + 1);
}

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
