#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

/*
** First element of the stack it is the top of this stack.
*/

typedef struct		s_stack
{
	struct s_stack	*next;
	int				value;
}					t_stack_list;

typedef struct
{
	t_stack_list	*list;
	int				len;
	char			letter;
}					t_stack;

typedef struct
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	unsigned char	flag_debug : 1;
}					t_main;

t_main		*init(void);
void		ft_error(void);
void		parsing(t_main *main_s, int ac, char **av);
void		push(t_stack *stack, int value);
int			pop(t_stack *stack);
void		swap(t_stack *stack);
void		rotate(t_stack *stack);
void		reverse_rotate(t_stack *stack);
int			get_median(t_stack *stack);
void		sort(t_stack *stack_a, t_stack *stack_b);

#endif