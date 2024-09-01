/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combined_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:11:54 by rtaboada          #+#    #+#             */
/*   Updated: 2024/09/02 00:10:57 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_both_swap(t_stack **a, t_stack **b)
{
	do_swap(a, FALSE);
	do_swap(b, FALSE);
	ft_printf("ss\n");
}

void	do_both_rotate(t_stack **a, t_stack **b, t_bool reverse)
{
	if (reverse)
	{
		do_reverse_rotate(a, FALSE);
		do_reverse_rotate(b, FALSE);
		ft_printf("rrr\n");
	}
	else
	{
		do_rotate(a, FALSE);
		do_rotate(b, FALSE);
		ft_printf("rr\n");
	}
}
