#include "push_swap.h"

int     main(int ac, char *av[])
{
	t_main  *main_s;

	main_s = init();
	parsing(main_s, ac, av);
	if (!is_sort(main_s->stack_a))
		sort(main_s);
	
	// t_stack_list *elem;

	// elem = main_s->stack_a->list;
	// while (elem)
	// {
	// 	ft_printf("%d\n", elem->value);
	// 	elem = elem->next;
	// }
	
	return (0);
}
