#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_stack_list *tmp;

	if (stack->len >= 2)
	{
		tmp = stack->list;
		stack->list = stack->list->next;
		tmp->next = stack->list->next;
		stack->list->next = tmp;
	}
}

void	rotate(t_stack *stack)
{
	t_stack_list	*list;

	if (stack->len >= 2)
	{
		list = stack->list;
		while (list->next)
			list = list->next;
		list->next = stack->list;
		stack->list = stack->list->next;
		list->next->next = NULL;
	}
}

void	reverse_rotate(t_stack *stack)
{
	t_stack_list	*list;
	t_stack_list	*last;

	if (stack->len >= 2)
	{
		list = stack->list;
		while (list->next->next)
			list = list->next;
		last = list->next;
		list->next = NULL;
		last->next = stack->list;
		stack->list = last;
	}
}

void	push(t_stack *stack, int value)
{
	t_stack_list *new;

	new = (t_stack_list *)malloc(sizeof(t_stack_list));
	(!new) ? ft_error() : 0;
	new->value = value;
	new->next = stack->list;
	stack->list = new;
	stack->len++;
}

int		pop(t_stack *stack)
{
	t_stack_list	*tmp;
	int	value;

	value = stack->list->value;
	tmp = stack->list->next;
	free(stack->list);
	stack->list = tmp;
	stack->len--;
	return (value);
}
