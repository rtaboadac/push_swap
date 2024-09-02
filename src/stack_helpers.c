/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 21:41:14 by rtaboada          #+#    #+#             */
/*   Updated: 2024/09/02 18:51:41 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_bool	set_node_num(char *num, t_stack *node)
{
	long	nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	if (*num == '-' || *num == '+')
	{
		if (*num == '-')
			sign = -1;
		num++;
		if (!*num)
			return (FALSE);
	}
	while (*num)
	{
		if (*num < '0' || *num > '9')
			return (FALSE);
		nbr = nbr * 10 + *num - '0';
		if ((nbr * sign > INT_MAX) || nbr * sign < INT_MIN)
			return (FALSE);
		num++;
	}
	node->number = nbr * sign;
	return (TRUE);
}

t_stack	*find_min(t_stack *stack, t_stack *bottom)
{
	int		min_nbr;
	int		bot_nbr;
	t_stack	*min;

	min_nbr = INT_MAX;
	min = NULL;
	if (bottom)
		bot_nbr = bottom->number;
	else
		bot_nbr = INT_MIN;
	while (stack)
	{
		if (bottom == NULL && stack->number == INT_MIN)
			return (stack);
		if (stack->number < min_nbr && stack->number > bot_nbr)
		{
			min_nbr = stack->number;
			min = stack;
		}
		stack = stack->next;
	}
	return (min);
}

t_stack	*find_max(t_stack *stack, t_stack *top)
{
	int		max_nbr;
	int		top_nbr;
	t_stack	*max;

	max_nbr = INT_MIN;
	max = NULL;
	if (top)
		top_nbr = top->number;
	else
		top_nbr = INT_MAX;
	while (stack)
	{
		if (top == NULL && stack->number == INT_MAX)
			return (stack);
		if (stack->number > max_nbr && stack->number < top_nbr)
		{
			max_nbr = stack->number;
			max = stack;
		}
		stack = stack->next;
	}
	return (max);
}

t_stack	*find_mid(t_stack *stack)
{
	t_stack	*max;
	t_stack	*min;

	min = find_min(stack, NULL);
	max = find_max(stack, NULL);
	while (min->number < max->number)
	{
		min = find_min(stack, min);
		max = find_max(stack, max);
	}
	return (min);
}
