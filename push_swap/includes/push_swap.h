#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

# define COUNT_OPERATIONS 11

/*
** First element of the stack - it is the top of this stack.
**
** @param sorted - reperesents whether particular elem is in sorted order or not.
*/

typedef struct		s_stack
{
	struct s_stack	*next;
	int				value;
	unsigned char	sorted : 1;
}					t_stack_list;

/*
** @param len - represents length of stack.
** @param letter - represents letter of a stack (a || b).
*/

typedef struct
{
	t_stack_list	*list;
	int				len;
}					t_stack;

typedef struct
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	unsigned char	flag_debug : 1;
	unsigned char	flag_show_command : 1;
}					t_main;

typedef struct
{
	char	*name;
	void	(*f)(t_main *);
}	t_op;

t_main		*init(void);
void		ft_error(void);
void		parsing(t_main *main_s, int ac, char **av);
void		push(t_stack *dest, t_stack *src);
void		swap(t_stack *stack);
void		rotate(t_stack *stack);
void		reverse_rotate(t_stack *stack);
int			get_median(t_stack *stack, int piece_len);
void		sort(t_main *main_s);
void		operation(char *op_name, t_main *main_s);

#endif
