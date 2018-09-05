/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 11:49:03 by tkiselev          #+#    #+#             */
/*   Updated: 2018/09/05 11:49:06 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char check_validity(char *str)
{
	static char		*operations[COUNT_OPERATIONS] = {
		"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"
	};
	unsigned char	i;

	i = 0;
	while (i < COUNT_OPERATIONS)
	{
		if (ft_strequ(str, operations[i]))
			return (1);
		i++;
	}
	return (0);
}

static void	get_commands(t_list **command)
{
	char *line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (!check_validity(line))
			ft_error();
		ft_list_pushback(command, line);
		ft_strdel(&line);
	}
}

static void	execute_commands(t_main *main_s, t_list *command)
{
	while (command)
	{
		operation(command->content, main_s);
		command = command->next;
	}
}

int     main(int ac, char *av[])
{
	t_main  *main_s;
	t_list	*command;

	command = NULL;
	main_s = init();
	parsing(main_s, ac, av);
	if (is_sort(main_s->stack_a))
		ft_printf("OK\n");
	else
	{
		get_commands(&command);
		execute_commands(main_s, command);
		if (is_sort(main_s->stack_a))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	return (0);
}
