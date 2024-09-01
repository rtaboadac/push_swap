/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 22:12:53 by rtaboada          #+#    #+#             */
/*   Updated: 2024/09/02 00:13:19 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	top_node(t_stack *node, t_stack **stack)
{
	int	cost;

	if (node->cost != 0)
		cost = node->cost;
	else
		cost = find_cost(*stack, node);
	if (cost >= 0)
		while (*stack != node)
			do_rotate(stack, TRUE);
	else
		while (*stack != node)
			do_reverse_rotate(stack, TRUE);
}

void	total_rotate(t_stack *goal, t_stack **a, t_stack **b, t_bool reverse)
{
	while (*a != goal->target && *b != goal)
		do_both_rotate(a, b, reverse);
	while (*a != goal->target)
	{
		if (reverse)
			do_reverse_rotate(a, TRUE);
		else
			do_rotate(a, TRUE);
	}
	while (*b != goal)
	{
		if (reverse)
			do_reverse_rotate(b, TRUE);
		else
			do_rotate(b, TRUE);
	}
}

void	total_top_node(t_stack *goal, t_stack **a, t_stack **b)
{
	t_bool	normal;
	t_bool	reverse;

	normal = goal->cost > 0 && goal->target->cost > 0;
	reverse = !normal && goal->cost < 0 && goal->target->cost < 0;
	if (normal || reverse)
		total_rotate(goal, a, b, reverse);
	else
	{
		top_node(goal->target, a);
		top_node(goal, b);
	}
}
