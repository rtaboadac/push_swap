/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 21:23:32 by rtaboada          #+#    #+#             */
/*   Updated: 2024/09/02 00:12:26 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	absolute(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

int	find_cost(t_stack *stack, t_stack *top)
{
	int	mid;
	int	pos;

	mid = stack_len(stack);
	pos = 0;
	while (stack && stack != top)
	{
		pos += 1;
		stack = stack->next;
	}
	if (pos <= mid / 2)
		return (pos);
	return (pos - mid);
}

t_stack	*find_target(t_stack *target_stack, t_stack *to_push)
{
	t_stack	*target;

	target = find_min(target_stack, to_push);
	if (!target)
		target = find_min(target_stack, NULL);
	return (target);
}

int	find_total_cost(int cost_a, int cost_b)
{
	int	abs_a;
	int	abs_b;

	abs_a = absolute(cost_a);
	abs_b = absolute(cost_b);
	if ((cost_a < 0 && cost_b < 0) || (cost_a > 0 && cost_b > 0))
	{
		if (abs_a > abs_b)
			return (abs_a);
		return (abs_b);
	}
	return (abs_a + abs_b);
}

t_stack	*find_cheapest(t_stack *stack)
{
	int		min;
	t_stack	*min_node;

	min = INT_MAX;
	min_node = NULL;
	if (stack->total_cost == 0)
		return (stack);
	while (stack)
	{
		if (stack->total_cost < min)
		{
			min = stack->total_cost;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}
