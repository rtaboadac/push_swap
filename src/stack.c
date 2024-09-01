/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 22:07:49 by rtaboada          #+#    #+#             */
/*   Updated: 2024/09/02 00:11:29 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_len(t_stack *stack)
{
	int	count;

	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

t_stack	*create_stack(int count, char **nums, char tag)
{
	t_stack	*stack;
	t_stack	*node;

	stack = NULL;
	while (count--)
	{
		node = push_bottom(&stack, tag);
		if (!node)
			return (NULL);
		if (!set_node_num(*nums, node) || stack_contains(node->number, &stack))
			return (NULL);
		nums++;
	}
	return (stack);
}

void	free_stack(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*tmp;

	if (!*stack)
		return ;
	curr = *stack;
	while (curr)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	*stack = NULL;
}

t_stack	*push_bottom(t_stack **stack, char tag)
{
	t_stack	*curr;
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (free_stack(stack), NULL);
	node->cost = 0;
	node->total_cost = 0;
	node->target = NULL;
	node->next = NULL;
	node->tag = tag;
	if (!*stack)
		return (*stack = node);
	curr = *stack;
	while (curr->next)
		curr = curr->next;
	curr->next = node;
	return (node);
}

t_stack	*find_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
