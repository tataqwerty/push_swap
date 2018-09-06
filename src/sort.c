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
		elem->piece_counter = 0;
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

static char check_ra(t_stack_list *elem, int median)
{
	int i;
	int first;
	int last;

	first = -1;
	last = -1;
	i = 0;
	while (elem)
	{
		if (first == -1 && elem->value < median)
			first = i;
		if (elem->value < median)
			last = i;
		elem = elem->next;
		i++;
	}
	last = i - last;
	if (first <= last)
		return (1);	// We are going to do ra.
	else
		return (0);	// We are going to do rra.
}

static void	return_values_to_the_bottom_a(t_main *main_s, int back_counter)
{
	if (back_counter < 0)
		back_counter = main_s->stack_a->len + back_counter;
	while (back_counter != 0 && back_counter != main_s->stack_a->len)
	{
		if ((main_s->stack_a->len - back_counter) < back_counter)
		{
			operation("ra", main_s);
			back_counter++;
		}
		else
		{
			operation("rra", main_s);
			back_counter--;
		}
	}
}

void		divide_stack_a(t_main *main_s, int piece_len, int median)
{
	int				dest_counter;
	int				back_counter;

	back_counter = 0;
	dest_counter = piece_len / 2;
	while (dest_counter > 0)
	{
		if (main_s->stack_a->list->value < median)
		{
			operation("pb", main_s);
			dest_counter--;
		}
		else if (check_ra(main_s->stack_a->list, median))
		{
			operation("ra", main_s);
			back_counter++;
		}
		else
		{
			operation("rra", main_s);
			(main_s->stack_a->list->value >= median) ? back_counter-- : 0;	// If a value that just have been added to the top of the stack_a is lower than the median, then I don't need to return this value, else if thie value is greater or equal to median, then I must return this value to the bottom.
		}
	}
	return_values_to_the_bottom_a(main_s, back_counter);
}


static char check_rb(t_stack_list *elem, int median)
{
	int i;
	int first;
	int last;

	first = -1;
	last = -1;
	i = 0;
	while (elem)
	{
		if (first == -1 && elem->value < median)
			first = i;
		if (elem->value > median)
			last = i;
		elem = elem->next;
		i++;
	}
	last = i - last;
	if (first <= last)
		return (1);	// We are going to do rb.
	else
		return (0);	// We are going to do rrb.
}

static void	return_values_to_the_bottom_b(t_main *main_s, int back_counter)
{
	if (back_counter < 0)
		back_counter = main_s->stack_b->len + back_counter;
	while (back_counter != 0 && back_counter != main_s->stack_b->len)
	{
		if ((main_s->stack_b->len - back_counter) < back_counter)
		{
			operation("rb", main_s);
			back_counter++;
		}
		else
		{
			operation("rrb", main_s);
			back_counter--;
		}
	}
}

void		divide_stack_b(t_main *main_s, int piece_len, int median)
{
	int				dest_counter;
	int				back_counter;

	back_counter = 0;
	dest_counter = (piece_len % 2 == 0) ? (piece_len / 2) : (piece_len / 2 + 1);
	while (dest_counter > 0)
	{
		if (main_s->stack_b->list->value >= median)
		{
			operation("pa", main_s);
			dest_counter--;
		}
		else if (check_rb(main_s->stack_b->list, median))
		{
			operation("rb", main_s);
			back_counter++;
		}
		else
		{
			operation("rrb", main_s);
			(main_s->stack_b->list->value <= median) ? back_counter-- : 0;	// If a value that just have been added to the top of the stack_a is lower than the median, then I don't need to return this value, else if thie value is greater or equal to median, then I must return this value to the bottom.
		}
	}
	return_values_to_the_bottom_b(main_s, back_counter);
}

void	sort_b(t_main *main_s, int piece_counter);

void	sort_a(t_main *main_s, int piece_counter)
{
	int		median;
	int		piece_len;

	pick_out_piece(main_s->stack_a, piece_counter);
	piece_len = length_of_piece(main_s->stack_a, piece_counter);
	if (piece_len <= 3)
	{
		sort_router(main_s, piece_len);
		assign_sorted(main_s->stack_a->list, piece_len);
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
		operation("pa", main_s);
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
	{
		return_piece_to_a(main_s, piece_len);
		return ;	// Cause I don't want to write lots of functions
	}
	median = get_median_of_piece(main_s->stack_b, piece_len);
	divide_stack_b(main_s, piece_len, median);
	sort_a(main_s, piece_counter + 1);
	sort_b(main_s, piece_counter);
	sort_a(main_s, piece_counter + 1);
}
