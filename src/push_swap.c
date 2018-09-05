#include "push_swap.h"

int		main(int ac, char *av[])
{
	t_main  *main_s;

	main_s = init();
	main_s->flag_show_command = 1;
	parsing(main_s, ac, av);
	if (!is_sort(main_s->stack_a))
		sort(main_s);
	return (0);
}
