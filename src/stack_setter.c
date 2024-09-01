/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_setter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 21:21:48 by rtaboada          #+#    #+#             */
/*   Updated: 2024/09/02 00:11:22 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_target(t_stack *from, t_stack *to)
{
	while (from)
	{
		from->target = find_target(to, from);
		from = from->next;
	}
}

void	set_cost(t_stack *stack)
{
	t_stack	*top;
	int		middle;
	int		position;

	middle = stack_len(stack);
	position = 0;
	top = stack;
	while (top)
	{
		if (position <= middle / 2)
			top->cost = position;
		else
			top->cost = position - middle;
		position += 1;
		top = top->next;
	}
}

void	set_total_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*curr;

	set_cost(stack_a);
	set_cost(stack_b);
	set_target(stack_b, stack_a);
	curr = stack_b;
	while (curr)
	{
		curr->total_cost = find_total_cost(curr->cost, curr->target->cost);
		curr = curr->next;
	}
}
