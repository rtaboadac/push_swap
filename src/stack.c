/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 20:00:28 by rtaboada          #+#    #+#             */
/*   Updated: 2024/08/25 20:09:08 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_stack	create_stack()
{
	t_stack	*stack;

	stack = (t_stack *) malloc(sizeof(t_stack));
	stack->data = NULL;
	stack->size = 0;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	free(stack->data);
	free(stack);
}
