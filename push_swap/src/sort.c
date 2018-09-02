#include "push_swap.h"

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	int mediana;

	if (stack_a->len <= 3)
		return ;
	mediana = get_median(stack_a);
	printf("mediana = %d\n", mediana);
}
