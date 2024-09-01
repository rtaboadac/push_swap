/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 21:40:22 by rtaboada          #+#    #+#             */
/*   Updated: 2024/09/02 00:10:52 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	stack_contains(int number, t_stack **stack)
{
	t_stack	*curr;

	curr = *stack;
	while (curr->next)
	{
		if (number == curr->number)
			return (TRUE);
		curr = curr->next;
	}
	return (FALSE);
}

t_bool	is_sorted(int min, t_stack *stack)
{
	t_stack	*start;
	t_stack	*end;

	start = stack;
	end = stack;
	while (stack->number != min && stack)
		stack = stack->next;
	while (stack)
	{
		end = stack->next;
		if (!stack->next)
		{
			end = start;
			if (stack->number > start->number)
				break ;
		}
		else if (stack->number > stack->next->number)
			break ;
		stack = end;
	}
	if (end->number == min)
		return (TRUE);
	return (FALSE);
}
