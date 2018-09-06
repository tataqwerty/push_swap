#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft.h"

# define COUNT_OPERATIONS	11
# define COUNT_PATTERNS		9

# define ASC	0
# define DESC	1

/*
** First element of the stack - it is the top of this stack.
**
** @param sorted - reperesents whether particular elem is in sorted order or not.
*/

typedef struct		s_stack
{
	struct s_stack	*next;
	int				value;
	int				piece_counter;
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

/*
** @param commands - represents an array of commands that I should use to sort.
** @param len - represents quantity of commands.
** @param check - it is a pointer to a function through which I will understand whether I need to execute commands from this elem or not to sort.
**
** Bullshit because commands have a length of 6 maximum.
*/

typedef struct
{
	char			*commands[6];
	unsigned char	len;
	char			(*check)(t_stack *, int);
}	t_pattern;

t_main		*init(void);
void		ft_error(void);
char		is_sort(t_stack *stack);
void		parsing(t_main *main_s, int ac, char **av);
int			get_median(t_stack *stack, int piece_len);
void		sort(t_main *main_s);
void		operation(char *op_name, t_main *main_s);
void		output_stacks(t_stack_list *elem_a, t_stack_list *elem_b, int a_len, int b_len);
void		sort_router(t_main *main_s, int piece_len);
void		divide_stack(t_main *main_s, int piece_len, int median);

/*
** Main stacks commands that will be used by operations such as sa, sb...
*/

void		push(t_stack *dest, t_stack *src);
void		swap(t_stack *stack);
void		rotate(t_stack *stack);
void		reverse_rotate(t_stack *stack);

/*
** All operations, just because it is easier.
*/

void	sa(t_main *main_s);
void	sb(t_main *main_s);
void	ss(t_main *main_s);
void	pa(t_main *main_s);
void	pb(t_main *main_s);
void	ra(t_main *main_s);
void	rb(t_main *main_s);
void	rr(t_main *main_s);
void	rra(t_main *main_s);
void	rrb(t_main *main_s);
void	rrr(t_main *main_s);

/*
** Patterns which help a program decide which commands to use in order to sort.
*/

char pattern_1(t_stack *stack, int piece_len);
char pattern_2(t_stack *stack, int piece_len);
char pattern_3(t_stack *stack, int piece_len);
char pattern_4(t_stack *stack, int piece_len);
char pattern_5(t_stack *stack, int piece_len);
char pattern_6(t_stack *stack, int piece_len);
char pattern_7(t_stack *stack, int piece_len);
char pattern_8(t_stack *stack, int piece_len);
char pattern_9(t_stack *stack, int piece_len);

#endif
