#include "push_swap.h"

static void	sort_router(t_stack *stack)
{
	ft_printf("sort_router\n");
}

/*
** @param dest_counter - how many elements will be transferred to dest.
*/

static void	divide_stack(t_stack *src, t_stack *dest, int median)
{
	int				dest_counter;

	dest_counter = src->len / 2;
	while (dest_counter > 0)
	{
		if (src->list->value < median)
		{
			push(dest, pop(src));
			dest_counter--;
			ft_printf("p%c\n", dest->letter);
		}
		else
		{
			rotate(src);
			ft_printf("r%c\n", src->letter);
		}
	}
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int median;

	median = get_median(stack_a);
	ft_printf("median = %d\n", median);

	if (stack_a->len <= 3)
	{
		sort_router(stack_a);
		return ;
	}


	divide_stack(stack_a, stack_b, median);

	sort(stack_a, stack_b);
}
