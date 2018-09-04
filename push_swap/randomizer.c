#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int ac, char *av[])
{
	int a[atoi(av[2]) - atoi(av[1])];
	int lower = atoi(av[1]);
	int upper = atoi(av[2]);
	int i = 0;

	while (i < (upper - lower))
	{
		a[i] = lower + i;
		i++;
	}

	srand(time(0));
	i = 0;

	int random_index;
	int tmp;

	while (i < (upper - lower))
	{
		tmp = a[i];
		random_index = rand() % (upper - lower);
		a[i] = a[random_index];
		a[random_index] = tmp;
		i++;
	}
	i = 0;
	while (i < (upper - lower))
	{
		printf("%d ", a[i]);
		i++;
	}
	return (0);
}
