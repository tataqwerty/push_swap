/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_router.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 20:59:59 by tkiselev          #+#    #+#             */
/*   Updated: 2018/09/07 21:00:03 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static short	find_pattern(t_pattern patterns[], t_main *main_s, int piece_len)
{
	short i;

	i = 0;
	while (i < COUNT_PATTERNS)
	{
		if (patterns[i].check(main_s->stack_a, piece_len))
			return (i);
		i++;
	}
	return (-1);
}

static void		sort_by_pattern(t_pattern patterns[], short pattern_counter, t_main *main_s)
{
	t_pattern	*pattern;
	char		*op_name;
	short		op_counter;

	op_counter = 0;
	pattern = &patterns[pattern_counter];
	while (op_counter < pattern->len)
	{
		op_name = pattern->commands[op_counter];
		operation(op_name, main_s);
		op_counter++;
	}
}

/*
** @param piece_len - length of unsorted part that needs to be sorted.
*/

void			sort_router(t_main *main_s, int piece_len)
{
	static t_pattern	patterns[COUNT_PATTERNS] = {
		{{"sa"}, 1, pattern_1},
		{{"ra", "sa", "rra"}, 3, pattern_2},
		{{"sa"}, 1, pattern_3},
		{{"rra"}, 1, pattern_4},
		{{"ra", "sa", "rra", "sa"}, 4, pattern_5},
		{{"ra"}, 1, pattern_6},
		{{"sa", "ra", "sa", "rra"}, 4, pattern_7},
		{{"ra", "sa"}, 2, pattern_8},
		{{"sa", "ra", "sa", "rra", "sa"}, 5, pattern_9}
	};
	short				pattern_counter;

	if (is_sort(main_s->stack_a))
		return ;
	pattern_counter = find_pattern(patterns, main_s, piece_len);
	if (pattern_counter == -1)
		ft_error();
	sort_by_pattern(patterns, pattern_counter, main_s);
}
