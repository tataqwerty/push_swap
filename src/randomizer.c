/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiselev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 20:59:41 by tkiselev          #+#    #+#             */
/*   Updated: 2018/09/07 20:59:44 by tkiselev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <time.h>

static void	ft_random(unsigned int n)
{
	int				arr[n];
	unsigned int	i;
	unsigned int	tmp;
	unsigned int	random_idx;

	i = 0;
	while (i < n)
	{
		arr[i] = i;
		i++;
	}
	i = 0;
	srand(time(0));
	while (i < n)
	{
		tmp = arr[i];
		random_idx = rand() % n;
		arr[i] = arr[random_idx];
		arr[random_idx] = tmp;
		i++;
	}
	i = 0;
	while (i < n)
		ft_printf("%d ", arr[i++]);
}

int			main(int ac, char *av[])
{
	if (ac == 2 && ft_is_uint(av[1]) && ft_atoi(av[1]) < 100000)
		ft_random(ft_atoi(av[1]));
	else
		ft_printf("Error");
	ft_printf("\n");
	return (0);
}
