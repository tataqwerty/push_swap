#include "libft.h"
#include <time.h>

static void	ft_random(unsigned int n)
{
	int 			arr[n];
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

int main(int ac, char *av[])
{
	if (ac == 2 && ft_is_uint(av[1]))
		ft_random(ft_atoi(av[1]));
	else
		ft_printf("Error");
	ft_printf("\n");
	return (0);
}
