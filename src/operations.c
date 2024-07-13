#include "push_swap.h"

void	do_swap(t_stack **stack, t_bool print)
{
	int	tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
	if (print)
		printf("s%c\n", (*stack)->tag);
}

void	do_push(t_stack **from, t_stack **to)
{
	t_stack	*tmp;

	if (!(*from))
		return ;
	tmp = *from;
	*from = (*from)->next;
	tmp->next = *to;
	*to = tmp;
	printf("p%c\n", (*to)->tag);
}

void	do_rotate(t_stack **stack, t_bool print)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	last = *stack;
	*stack = (*stack)->next;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	if (print)
		printf("r%c\n", (*stack)->tag);
}

void	do_reverse_rotate(t_stack **stack, t_bool print)
{
	t_stack	*tmp;
	t_stack	*second_last;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	second_last = NULL;
	while (tmp->next)
	{
		second_last = tmp;
		tmp = tmp->next;
	}
	second_last->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
	if (print)
		printf("rr%c\n", (*stack)->tag);
}
