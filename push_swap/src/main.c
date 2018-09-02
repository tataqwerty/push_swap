#include "push_swap.h"

void    router(t_main *main_s)
{
	if (main_s->flag_debug)
	{
		;
	}
	else
		sort(main_s->stack_a, main_s->stack_b);
}

int     main(int ac, char *av[])
{
	t_main  *main_s;

	main_s = init();
	parsing(main_s, ac, av);
	router(main_s);
	return (0);
}
