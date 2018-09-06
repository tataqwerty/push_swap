#include "push_swap.h"

/*
** This function returns unsorted part from stack_b.
*/

static void	return_piece(t_main *main_s, int piece_len)
{
	while (piece_len > 0)
	{
		operation("pa", main_s);
		piece_len--;
	}
}

static int	length_of_unsorted_part(t_stack *stack)
{
	t_stack_list	*elem;
	int				quantity;

	quantity = 0;
	elem = stack->list;
	while (elem)
	{
		if (!elem->sorted)
			quantity++;
		elem = elem->next;
	}
	return (quantity);
}

static void	assign_sorted(t_stack_list *elem, int piece_len)
{
	while (piece_len > 0)
	{
		elem->sorted = 1;
		elem = elem->next;
		piece_len--;
	}
}

/*
** @param piece_len - represents length of unsorted part of the stack_a.
*/

void	sort(t_main *main_s)
{
	int		median;
	int		piece_len;

	piece_len = length_of_unsorted_part(main_s->stack_a);
	median = get_median(main_s->stack_a, piece_len);
	if (piece_len <= 3)
	{
		sort_router(main_s, piece_len);
		assign_sorted(main_s->stack_a->list, piece_len);
		return ;
	}
	divide_stack(main_s, piece_len, median);
	sort(main_s);
	return_piece(main_s, piece_len / 2);
	sort(main_s);
}
