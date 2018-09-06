#include "push_swap.h"

/*
** @param dest_counter - how many elements will be transferred to dest.
** @param back_counter - how many elements have been thrown to the end of stack_a after division.
*/

// void		divide_stack(t_main *main_s, int piece_len, int median)
// {
// 	int				dest_counter;
// 	int				back_counter;

// 	back_counter = 0;
// 	dest_counter = piece_len / 2;
// 	while (dest_counter > 0)
// 	{
// 		if (main_s->stack_a->list->value < median)	// If first elem of stack_a has a value that lower than median => throw this elem to stack_b.
// 		{
// 			operation("pb", main_s);
// 			dest_counter--;
// 			piece_len--;
// 		}
// 		else
// 		{
// 			operation("ra", main_s);
// 			back_counter++;
// 		}
// 	}
// 	if (back_counter != 0 && back_counter != main_s->stack_a->len)	// If there are elements have been thrown to the end of stack_a, return this elements to the initial position, if needed.
// 		while (back_counter-- > 0)
// 			operation("rra", main_s);
// }

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

static void	return_values_to_the_bottom(t_main *main_s, int back_counter)
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

/*
** @param dest_counter - how many elements will be transferred to dest.
** @param back_counter - how many elements have been thrown to the end of stack_a after division.
*/

void		divide_stack(t_main *main_s, int piece_len, int median)
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
	return_values_to_the_bottom(main_s, back_counter);
}
