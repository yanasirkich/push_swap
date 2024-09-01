/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 16:57:40 by ysirkich          #+#    #+#             */
/*   Updated: 2024/09/01 17:30:22 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		partition(int *array, int low, int high);
static void	swap(int *a,int *b);

void	quicksort(int *array, int low, int high)
{
	int	pivot;

	if (high > low)
	{
		pivot = partition(array, low, high);//returns the index of the pivot after partitioning
		quicksort(array, low, pivot - 1);
		quicksort(array, pivot + 1, high);
	}
}

 static int	partition(int *array, int low, int high)
{
	int	pivot;
	int	index; //the next smaller element
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
	swap(&array[index + 1], &array[high]);//pivot to the correct position
	return (index + 1);
}

static void	swap(int *a,int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}