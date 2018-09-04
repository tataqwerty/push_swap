#include "push_swap.h"

/*
** 2
** 1
*/

char pattern_1(t_stack *stack, int piece_len)
{
	int a;
	int b;

	if (piece_len == 2)
	{
		a = stack->list->value;
		b = stack->list->next->value;
		if (a > b)
			return (1);
	}
	return (0);
}

/*
** 1
** 3
** 2
*/

char	pattern_2(t_stack *stack, int piece_len)
{
	int a;
	int b;
	int c;

	if (piece_len == 3)
	{
		a = stack->list->value;
		b = stack->list->next->value;
		c = stack->list->next->next->value;
		if (a < c && c < b)
			return (1);
	}
	return (0);
}

/*
** 2
** 1
** 3
*/

char	pattern_3(t_stack *stack, int piece_len)
{
	int a;
	int b;
	int c;

	if (piece_len == 3)
	{
		a = stack->list->value;
		b = stack->list->next->value;
		c = stack->list->next->next->value;
		if (b < a && a < c)
			return (1);
	}
	return (0);
}

/*
** 2
** 3
** 1
*/

char	pattern_4(t_stack *stack, int piece_len)
{
	int a;
	int b;
	int c;

	if (piece_len == 3 && stack->len == 3)
	{
		a = stack->list->value;
		b = stack->list->next->value;
		c = stack->list->next->next->value;
		if (c < a && a < b)
			return (1);
	}
	return (0);
}

/*
** 2
** 3
** 1
** something here
*/

char	pattern_5(t_stack *stack, int piece_len)
{
	int a;
	int b;
	int c;

	if (piece_len == 3 && stack->len != 3)
	{
		a = stack->list->value;
		b = stack->list->next->value;
		c = stack->list->next->next->value;
		if (c < a && a < b)
			return (1);
	}
	return (0);
}
