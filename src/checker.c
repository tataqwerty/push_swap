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

int	main(int ac, char *av[])
{
	t_main	*main_s;
	char	*line;

	line = NULL;
	main_s = init();
	parsing(main_s, ac, av);
	if (is_sort(main_s->stack_a))
		ft_printf("OK\n");
	else
	{
		while (get_next_line(0, &line))
		{
			operation(line, main_s);
			ft_strdel(&line);
		}
		if (is_sort(main_s->stack_a))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	return (0);
}
