#include "push_swap.h"

static int	length_of_piece(t_stack *stack, int piece_counter)
{
	t_stack_list	*elem;
	int				quantity;

	quantity = 0;
	elem = stack->list;
	while (elem)
	{
		if (elem->piece_counter == piece_counter)	// This element belongs to a needed piece.
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

static void pick_out_piece(t_stack *stack, int piece_counter)
{
	t_stack_list *elem;

	elem = stack->list;
	while (elem)
	{
		if (elem->piece_counter == piece_counter)	// Such piece already exists.
			return ;
		else if (!elem->sorted)	// If elem doesn't refer to a sorted piece, then I create a new piece with this element.
			elem->piece_counter = piece_counter;
		elem = elem->next;
	}
}

static void	divide_stack_a()
{
	
}

static void	divide_stack_b()
{

}

void	sort_a(t_main *main_s, int piece_counter)
{
	int		median;
	int		piece_len;

	pick_out_piece(main_s->stack_a, piece_counter);
	piece_len = length_of_piece(main_s->stack_a, piece_counter);
	if (piece_len <= 3)
	{
		sort_router(main_s->stack_a, piece_len);
		assign_sorted(main_s->stack_a, piece_len);
		return ;
	}
	median = get_median_of_piece(main_s->stack_a, piece_len);
	divide_stack_a(main_s, piece_len, median);
	sort_a(main_s, piece_counter + 1);
	sort_b(main_s, piece_counter);
	sort_a(main_s, piece_counter + 1);
}

static void return_piece_to_a(t_main *main_s, int piece_len)
{
	while (piece_len > 0)
	{
		operation("", main_s);
		piece_len--;
	}
}

void	sort_b(t_main *main_s, int piece_counter)
{
	int		median;
	int		piece_len;

	pick_out_piece(main_s->stack_b, piece_counter);
	piece_len = length_of_piece(main_s->stack_b, piece_counter);
	if (piece_len <= 3)
		return ;	// Cause I don't want to write lots of functions
	median = get_median_of_piece(main_s->stack_b, piece_len);
	divide_stack_b(main_s, piece_len, median);
	sort_a(main_s, piece_counter + 1);
	sort_b(main_s, piece_counter);
	sort_a(main_s, piece_counter + 1);
}
