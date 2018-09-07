/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 20:58:47 by tkiselev          #+#    #+#             */
/*   Updated: 2018/09/07 20:58:49 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** This function here because I don't want to crenew fiate a le operation_functions_3.c just for a single function.
*/

void	rrr(t_main *main_s)
{
	reverse_rotate(main_s->stack_a);
	reverse_rotate(main_s->stack_b);
}

/*
** Operations for this function are in two files: operation_functions_1.c and operation_functions_2.c
**
** This function shows name of operation which it fulfills just in case if flag_show_command is ON.
** This function output_stacks just in case if flag_debug is ON.
*/

void	operation(char *op_name, t_main *main_s)
{
	unsigned char	i;
	static t_op		operations[COUNT_OPERATIONS] = {
		{"sa", sa}, {"sb", sb}, {"ss", ss}, {"pa", pa},
		{"pb", pb}, {"ra", ra}, {"rb", rb}, {"rr", rr},
		{"rra", rra}, {"rrb", rrb}, {"rrr", rrr}
	};

	i = 0;
	while (i < COUNT_OPERATIONS)
	{
		if (ft_strequ(operations[i].name, op_name))
		{
			operations[i].f(main_s);
			if (main_s->flag_show_command)
				ft_printf("%s\n", op_name);
			if (main_s->flag_debug)
				output_stacks(main_s->stack_a->list, main_s->stack_b->list,
				main_s->stack_a->len, main_s->stack_b->len);
			return ;
		}
		i++;
	}
	ft_error();
}
