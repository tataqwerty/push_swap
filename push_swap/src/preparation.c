#include "push_swap.h"

void			ft_error(void)
{
	ft_putstr("Error\n");
	exit(0);
}

static t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	(!stack) ? ft_error() : 0;
	stack->len = 0;
	stack->list = NULL;
	return (stack);
}

t_main			*init(void)
{
	t_main	*main_s;

	main_s = (t_main *)malloc(sizeof(t_main));
	(!main_s) ? ft_error() : 0;
	main_s->flag_debug = 0;
	main_s->stack_a = init_stack();
	main_s->stack_b = init_stack();
	return (main_s);
}

static void		parse_arg(t_main *main_s, char *arg)
{
	int		i;
	char	**arguments;

	arguments = ft_strsplit(arg, ' ');
	(!arguments) ? ft_error() : 0;
	i = 0;
	while (arguments[i])
	{
		if (ft_is_int(arguments[i]))
			push(main_s->stack_a, ft_atoi(arguments[i]));
		else
			ft_error();
		free(arguments[i]);
		i++;
	}
	free(arguments);	
}

void			parsing(t_main *main_s, int ac, char **av)
{
	int i;

	i = 1;
	if (ac >= 2)
	{
		while (i < ac)
		{
			if (ft_strequ(av[i], "-v"))
				main_s->flag_debug = 1;
			else
				parse_arg(main_s, av[i]);
			i++;
		}
	}
	else
		ft_error();	// USAGE
}
