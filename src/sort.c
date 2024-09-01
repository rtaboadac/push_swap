/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:17:16 by rtaboada          #+#    #+#             */
/*   Updated: 2024/09/02 00:11:15 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a_to_b(t_stack **a, t_stack **b)
{
	int		nodes;
	t_stack	*middle;

	nodes = stack_len(*a);
	middle = find_mid(*a);
	if (nodes-- > 3)
		do_push(a, b);
	if (nodes == 4)
	{
		nodes -= 1;
		do_push(a, b);
	}
	while (nodes > 3)
	{
		do_push(a, b);
		if ((*b)->number > middle->number)
			do_rotate(b, TRUE);
		nodes--;
	}
}

void	push_b_to_a(t_stack **a, t_stack **b)
{
	t_stack	*goal;

	while (*b)
	{
		set_total_cost(*a, *b);
		goal = find_cheapest(*b);
		total_top_node(goal, a, b);
		(*b)->cost = 0;
		do_push(b, a);
	}
}

void	sort_three(t_stack **stack)
{
	t_stack	*max;

	max = find_max(*stack, NULL);
	if ((*stack)->number == max->number)
		do_rotate(stack, TRUE);
	if ((*stack)->next->number == max->number)
		do_reverse_rotate(stack, TRUE);
	if ((*stack)->number > (*stack)->next->number)
		do_swap(stack, TRUE);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	t_stack	*min;

	min = find_min(*a, NULL);
	if (is_sorted(min->number, *a))
		return (top_node(min, a));
	push_a_to_b(a, b);
	sort_three(a);
	push_b_to_a(a, b);
	min->cost = 0;
	top_node(min, a);
}
