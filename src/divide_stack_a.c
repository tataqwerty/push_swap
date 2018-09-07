/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 20:58:19 by tkiselev          #+#    #+#             */
/*   Updated: 2018/09/07 20:58:21 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	ra_better_than_rra(t_stack_list *elem, int median)
{
	int first;
	int last;
	int i;

	first = -1;
	last = -1;
	i = 0;
	while (elem)
	{
		if (first == -1 && elem->value < median)
			first = i;
		if (elem->value < median)
			last = i;
		elem = elem->next;
		i++;
	}
	last = i - last;
	if (first <= last)
		return (1);
	else
		return (0);
}

static void	return_back_a(t_main *main_s, int back_counter)
{
	if (back_counter < 0)
		back_counter = main_s->stack_a->len + back_counter;
	while (back_counter != 0 && back_counter != main_s->stack_a->len)
	{
		if ((main_s->stack_a->len - back_counter) < back_counter)
		{
			operation("ra", main_s);
			back_counter++;
		}
		else
		{
			operation("rra", main_s);
			back_counter--;
		}
	}
}

/*
** Returns how many elements have been thrown to stack_b.
**
** @param dest_counter - how many elements will be transferred to dest.
** @param back_counter - how many elements have been thrown to the end of stack after division.
*/

int			divide_piece_a(t_main *main_s, int piece_len, int median)
{
	int dest_counter;
	int back_counter;

	dest_counter = piece_len / 2;
	back_counter = 0;
	while (dest_counter > 0)
	{
		if (main_s->stack_a->list->value < median)
		{
			operation("pb", main_s);
			dest_counter--;
		}
		else if (ra_better_than_rra(main_s->stack_a->list, median))
		{
			operation("ra", main_s);
			back_counter++;
		}
		else
		{
			operation("rra", main_s);
			(main_s->stack_a->list->value >= median) ? back_counter-- : 0;
		}
	}
	return_back_a(main_s, back_counter);
	return (piece_len / 2);
}
