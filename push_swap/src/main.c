#include "push_swap.h"

int     main(int ac, char *av[])
{
	t_main  *main_s;

	main_s = init();
	parsing(main_s, ac, av);
	sort(main_s);
	return (0);
}
