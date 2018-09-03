#include "push_swap.h"

static void	sort_router(t_main *main_s)
{
	ft_printf("sort_router\n");
}

/*
** @param dest_counter - how many elements will be transferred to dest.
*/

static void	divide_stack(t_main *main_s, int piece_len, int median)
{
	int				dest_counter;
	int				back_counter;

	back_counter = 0;
	dest_counter = piece_len / 2;
	while (dest_counter > 0)
	{
		if (main_s->stack_a->list->value < median)	// If first elem of stack_a has a value that lower than median => throw this elem to stack_b.
		{
			operation("pb", main_s);
			dest_counter--;
			piece_len--;
		}
		else
		{
			operation("ra", main_s);
			back_counter++;
		}
	}
	if (back_counter != 0 && back_counter != piece_len)
		while (back_counter-- > 0)
			operation("rra", main_s);
}

static void	return_piece(t_main *main_s, int piece_len)
{
	while (piece_len > 0)
	{
		operation("pa", main_s);
		piece_len--;
	}
}

static int	quantity_of_unsorted_elems(t_stack *stack)
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

/*
** @param piece_len - represents length of unsorted part of the stack_a.
*/

void	sort(t_main *main_s)
{
	int		median;
	int		piece_len;

	piece_len = quantity_of_unsorted_elems(main_s->stack_a);
	printf("piece_len = %d\n", piece_len);
	median = get_median(main_s->stack_a, piece_len);
	printf("median = %d\n", median);
	if (piece_len <= 3)
	{
		sort_router(main_s);
		// assign every element of piece flag sorted to 1.
		return ;
	}
	divide_stack(main_s, piece_len, median);
	sort(main_s);
	return_piece(main_s, piece_len / 2);
	sort(main_s);
}
