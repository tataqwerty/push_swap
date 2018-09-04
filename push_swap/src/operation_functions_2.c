#include "push_swap.h"

void	ra(t_main *main_s)
{
	rotate(main_s->stack_a);
}

void	rb(t_main *main_s)
{
	rotate(main_s->stack_b);
}

void	rr(t_main *main_s)
{
	rotate(main_s->stack_a);
	rotate(main_s->stack_b);
}

void	rra(t_main *main_s)
{
	reverse_rotate(main_s->stack_a);
}

void	rrb(t_main *main_s)
{
	reverse_rotate(main_s->stack_b);
}
