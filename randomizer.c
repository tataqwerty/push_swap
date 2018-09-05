#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int ac, char *av[])
{
	int arr[atoi(av[1])];
	int arr_counter;
	int i;
	int tmp;
	int random_idx;

	i = 0;
	arr_counter = atoi(av[1]);
	while (i < arr_counter)
	{
		arr[i] = i;
		i++;
	}
	i = 0;
	srand(time(0));
	while (i < arr_counter)
	{
		tmp = arr[i];
		random_idx = rand() % arr_counter;
		arr[i] = arr[random_idx];
		arr[random_idx] = tmp;
		i++;
	}
	i = 0;
	while (i < arr_counter)
		printf("%d ", arr[i++]);
	printf("\n");
	return (0);
}
