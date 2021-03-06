/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 20:59:08 by tkiselev          #+#    #+#             */
/*   Updated: 2018/09/07 20:59:09 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	length_of_num(int n)
{
	int len;

	len = 1;
	if (n < 0)
		len++;
	while ((n /= 10))
		len++;
	return (len);
}

static int	get_max_len_num(t_stack_list *elem)
{
	int max_len_num;
	int tmp_len_num;

	max_len_num = 0;
	while (elem)
	{
		tmp_len_num = length_of_num(elem->value);
		if (tmp_len_num > max_len_num)
			max_len_num = tmp_len_num;
		elem = elem->next;
	}
	return (max_len_num);
}

void		output_stacks(t_stack_list *elem_a, t_stack_list *elem_b, int a_len, int b_len)
{
	int	max_len_num;

	max_len_num = get_max_len_num(elem_a);
	while (a_len > b_len)
	{
		ft_printf("%-d\n", elem_a->value);
		elem_a = elem_a->next;
		a_len--;
	}
	while (b_len > a_len)
	{
		ft_printf("%*s %-d\n", max_len_num, " ", elem_b->value);
		elem_b = elem_b->next;
		b_len--;
	}
	while (a_len > 0 && b_len > 0)
	{
		ft_printf("%-*d %-d\n", max_len_num, elem_a->value, elem_b->value);
		elem_a = elem_a->next;
		elem_b = elem_b->next;
		a_len--;
		b_len--;
	}
	ft_printf("%-*s _\n%-*s b\n\n", max_len_num, "_", max_len_num, "a");
}
