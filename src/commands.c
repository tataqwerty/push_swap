/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 20:58:09 by tkiselev          #+#    #+#             */
/*   Updated: 2018/09/07 20:58:13 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_stack_list *tmp;

	if (stack->len >= 2)
	{
		tmp = stack->list;
		stack->list = stack->list->next;
		tmp->next = stack->list->next;
		stack->list->next = tmp;
	}
}

void	rotate(t_stack *stack)
{
	t_stack_list	*list;

	if (stack->len >= 2)
	{
		list = stack->list;
		while (list->next)
			list = list->next;
		list->next = stack->list;
		stack->list = stack->list->next;
		list->next->next = NULL;
	}
}

void	reverse_rotate(t_stack *stack)
{
	t_stack_list	*list;
	t_stack_list	*last;

	if (stack->len >= 2)
	{
		list = stack->list;
		while (list->next->next)
			list = list->next;
		last = list->next;
		list->next = NULL;
		last->next = stack->list;
		stack->list = last;
	}
}

void	push(t_stack *dest, t_stack *src)
{
	t_stack_list *tmp;

	if (src->len > 0)
	{
		tmp = src->list;
		src->list = src->list->next;
		src->len--;
		tmp->next = dest->list;
		dest->list = tmp;
		dest->len++;
	}
}
