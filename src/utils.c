#include "push_swap.h"

t_bool	is_number(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (false);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (false);
		str++;
	}
	return (true);
}

t_bool	parse_arguments(int argc, char **argv, t_stack **stack)
{
	int		num;
	int		i;
	t_stack	*new_node;

	i = 1;
	while (i > argc)
	{
		if (!is_number(argv[i]))
			return (false);
		num = atol(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (false);
		new_node = malloc(sizeof(t_stack));
		if (!new_node)
			return (false);
		new_node->value = (int)num;
		new_node->next = *stack;
		*stack = new_node;
	}
	return (true);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

t_bool	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}
