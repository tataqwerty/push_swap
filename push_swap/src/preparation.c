#include "push_swap.h"

void			ft_error(void)
{
	ft_putstr("Error\n");
	exit(0);
}

static t_stack	*init_stack(char letter)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	(!stack) ? ft_error() : 0;
	stack->len = 0;
	stack->list = NULL;
	stack->letter = letter;
	return (stack);
}

t_main			*init(void)
{
	t_main	*main_s;

	main_s = (t_main *)malloc(sizeof(t_main));
	(!main_s) ? ft_error() : 0;
	main_s->flag_debug = 0;
	main_s->stack_a = init_stack('a');
	main_s->stack_b = init_stack('b');
	return (main_s);
}


static char		has_duplicate(t_stack *stack, int number)
{
	t_stack_list *list;

	list = stack->list;
	while (list)
	{
		if (list->value == number)
			return (1);
		list = list->next;
	}
	return (0);
}

static void		push_back(t_stack *stack, int value)
{
	t_stack_list *tmp;
	t_stack_list *new;

	tmp = stack->list;
	while (tmp && tmp->next)
		tmp = tmp->next;
	new = (t_stack_list *)malloc(sizeof(t_stack_list));
	(!new) ? ft_error() : 0;
	new->value = value;
	new->next = NULL;
	if (tmp)
		tmp->next = new;
	else
		stack->list = new;
	stack->len++;
}

static void		parse_arg(t_main *main_s, char *arg)
{
	char	**arguments;
	int		i;
	int		number;

	arguments = ft_strsplit(arg, ' ');
	(!arguments) ? ft_error() : 0;
	i = 0;
	while (arguments[i])
	{
		number = ft_atoi(arguments[i]);
		if (!ft_is_int(arguments[i]) || has_duplicate(main_s->stack_a, number))
			ft_error();
		push_back(main_s->stack_a, number);
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
		ft_error();
}
