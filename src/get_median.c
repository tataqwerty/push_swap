/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 20:58:34 by tkiselev          #+#    #+#             */
/*   Updated: 2018/09/07 20:58:35 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_idx(int arr[], int arr_len, int value)
{
	int	i;

	i = 0;
	while (i < arr_len)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

static void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
** If pivot_idx == median_idx, then median == pivot.
**
** else if pivot_idx > median_idx, then median is in the left side,
** so I call find_median recursively with params of this array,
** but limits the size of this array just to the pivot_idx.
**
** else if pivot_idx < median_idx, then median is in the right side,
** so I call find_median recursively with params of array after pivot,
** and median_idx also reduce on pivot_idx.
*/

static	int	find_median(int arr[], int arr_len, int median_idx)
{
	int pivot;
	int pivot_idx;
	int i;
	int j;

	pivot = arr[median_idx];
	i = 0;
	j = arr_len - 1;
	while (i < j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		ft_swap(&arr[i], &arr[j]);
	}
	pivot_idx = find_idx(arr, arr_len, pivot);
	if (pivot_idx > median_idx)
		return (find_median(arr, pivot_idx, median_idx));
	else if (pivot_idx < median_idx)
		return (find_median(arr + pivot_idx + 1, arr_len - pivot_idx - 1, median_idx - pivot_idx - 1));	// ±1 because of the pivot.
	else
		return (pivot);
}

int			get_median_of_piece(t_stack_list *elem, int piece_len)
{
	int				arr[piece_len];
	int				i;

	i = 0;
	while (elem && i < piece_len)
	{
		arr[i] = elem->value;
		i++;
		elem = elem->next;
	}
	return (find_median(arr, piece_len, piece_len / 2));
}
