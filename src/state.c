/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 20:09:14 by rtaboada          #+#    #+#             */
/*   Updated: 2024/08/25 20:32:23 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_state	*copy_state(t_state *state)
{
	t_state *new_state = (t_state*) malloc(sizeof(t_state));
   	new_state->a->size = state->a->size;
	new_state->a->data = create_stack(state->a->size);
	new_state->a->data = ft_memcpy(new_state->a->data, state->a->data, sizeof(int) * state->a->size);
	
	new_state->b->size = state->b->size;	
	new_state->b->data = create_stack(state->b->size);
	new_state->b->data = ft_memcpy(new_state->b->data, state->b->data, sizeof(int) * state->b->size);


}
