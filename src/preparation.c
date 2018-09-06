#include "push_swap.h"

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
	new->next = NULL;
	new->value = value;
	new->piece_counter = 0;
	new->sorted = 0;
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
