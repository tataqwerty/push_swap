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

void	rrr(t_main *main_s)
{
	reverse_rotate(main_s->stack_a);
	reverse_rotate(main_s->stack_b);
}

void	output_stacks(t_main *main_s)
{

}

void	operation(char *op_name, t_main *main_s)
{
	unsigned char	i;
	static t_op		operations[11] = {
		{"sa", sa}, {"sb", sb}, {"ss", ss}, {"pa", pa}, 
		{"pb", pb}, {"ra", ra}, {"rb", rb}, {"rr", rr},
		{"rra", rra}, {"rrb", rrb}, {"rrr", rrr}
	};

	i = 0;
	while (i < COUNT_OPERATIONS)
	{
		if (ft_strequ(operations[i].name, op_name))
		{
			operations[i].f(main_s);
			if (main_s->flag_show_command)
				ft_printf("%s\n", op_name);
			if (main_s->flag_debug)
				output_stacks(main_s);
			return ;
		}
		i++;
	}
	ft_error();
}
