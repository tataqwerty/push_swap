#include "push_swap.h"

static void	return_to_stack_a(t_main *main_s, int piece_len)
{
	while (piece_len > 0)
	{
		operation("pa", main_s);
		piece_len--;
	}
}

static void	sort_b(t_main *main_s, int piece_len)
{
	int median;
	int thrown_to_stack_a;

	if (piece_len <= 3)
	{
		return_to_stack_a(main_s, piece_len);
		sort_a(main_s, piece_len);
		return ;
	}
	median = get_median_of_piece(main_s->stack_b->list, piece_len);

	thrown_to_stack_a = divide_piece_b(main_s, piece_len, median);

	sort_a(main_s, thrown_to_stack_a);

	sort_b(main_s, piece_len - thrown_to_stack_a);
}

void	sort_a(t_main *main_s, int piece_len)
{
	int median;
	int thrown_to_stack_b;

	if (piece_len <= 3)
	{
		sort_router(main_s, piece_len);
		return ;
	}
	median = get_median_of_piece(main_s->stack_a->list, piece_len);

	thrown_to_stack_b = divide_piece_a(main_s, piece_len, median);

	sort_a(main_s, piece_len - thrown_to_stack_b);

	sort_b(main_s, thrown_to_stack_b);
}
