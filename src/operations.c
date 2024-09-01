/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 13:16:24 by rtaboada          #+#    #+#             */
/*   Updated: 2024/09/02 00:13:08 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char	get_opposite_stack_tag(t_stack *stack)
{
	if (!stack || stack->tag == 'a')
		return ('b');
	return ('a');
}

void	do_swap(t_stack **stack, t_bool print)
{
	t_stack	*first;
	t_stack	*second;

	if (!(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	*stack = second;
	second->next = first;
	if (print)
		ft_printf("s%c\n", (*stack)->tag);
}

void	do_push(t_stack **from, t_stack **to)
{
	t_stack	*first;

	if (!*from)
		return ;
	first = *from;
	*from = first->next;
	first->next = *to;
	first->tag = get_opposite_stack_tag(first);
	*to = first;
	ft_printf("p%c\n", (*to)->tag);
}

void	do_rotate(t_stack **stack, t_bool print)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack)
		return ;
	if (!(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	last->next = first;
	first->next = NULL;
	if (print)
		ft_printf("r%c\n", (*stack)->tag);
}

void	do_reverse_rotate(t_stack **stack, t_bool print)
{
	t_stack	*last;
	t_stack	*before_last;

	if (!*stack)
		return ;
	if (!(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	last->next = *stack;
	*stack = last;
	before_last->next = NULL;
	if (print)
		ft_printf("rr%c\n", (*stack)->tag);
}
