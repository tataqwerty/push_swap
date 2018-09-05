/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   staff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 11:49:47 by tkiselev          #+#    #+#             */
/*   Updated: 2018/09/05 11:49:51 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	(!stack) ? ft_error() : 0;
	stack->len = 0;
	stack->list = NULL;
	return (stack);
}

t_main			*init(void)
{
	t_main	*main_s;

	main_s = (t_main *)malloc(sizeof(t_main));
	(!main_s) ? ft_error() : 0;
	main_s->stack_a = init_stack();
	main_s->stack_b = init_stack();
	main_s->flag_debug = 0;
	main_s->flag_show_command = 0;
	return (main_s);
}

void			ft_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

char			is_sort(t_stack *stack)
{
	t_stack_list	*cur;
	t_stack_list	*next;

	cur = stack->list;
	while (cur)
	{
		next = cur->next;
		if (next && next->value < cur->value)
			return (0);
		cur = next;
	}
	return (1);
}
