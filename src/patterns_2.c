#include "push_swap.h"

/*
** 3
** 1
** 2
*/

char pattern_6(t_stack *stack, int piece_len)
{
	int a;
	int b;
	int c;

	if (piece_len == 3 && stack->len == 3)
	{
		a = stack->list->value;
		b = stack->list->next->value;
		c = stack->list->next->next->value;
		if (b < c && c < a)
			return (1);
	}
	return (0);
}

/*
** 3
** 1
** 2
** something here
*/

char pattern_7(t_stack *stack, int piece_len)
{
	int a;
	int b;
	int c;

	if (piece_len == 3 && stack->len != 3)
	{
		a = stack->list->value;
		b = stack->list->next->value;
		c = stack->list->next->next->value;
		if (b < c && c < a)
			return (1);
	}
	return (0);
}

/*
** 3
** 2
** 1
*/

char pattern_8(t_stack *stack, int piece_len)
{
	int a;
	int b;
	int c;

	if (piece_len == 3 && stack->len == 3)
	{
		a = stack->list->value;
		b = stack->list->next->value;
		c = stack->list->next->next->value;
		if (c < b && b < a)
			return (1);
	}
	return (0);
}

/*
** 3
** 2
** 1
** something here
*/

char pattern_9(t_stack *stack, int piece_len)
{
	int a;
	int b;
	int c;

	if (piece_len == 3 && stack->len != 3)
	{
		a = stack->list->value;
		b = stack->list->next->value;
		c = stack->list->next->next->value;
		if (c < b && b < a)
			return (1);
	}
	return (0);
}
