#include "push_swap.h"

void	sa(t_main *main_s)
{
	swap(main_s->stack_a);
}

void	sb(t_main *main_s)
{
	swap(main_s->stack_b);
}

void	ss(t_main *main_s)
{
	swap(main_s->stack_a);
	swap(main_s->stack_b);
}

void	pa(t_main *main_s)
{
	push(main_s->stack_a, main_s->stack_b);
}

void	pb(t_main *main_s)
{
	push(main_s->stack_b, main_s->stack_a);
}
