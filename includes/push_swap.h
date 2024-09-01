/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 21:18:44 by rtaboada          #+#    #+#             */
/*   Updated: 2024/09/01 22:31:47 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/ft_printf/ft_printf.h"
# include "../lib/libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int				number;
	int				cost;
	int				total_cost;
	struct s_stack	*target;
	struct s_stack	*next;
	char			tag;
}					t_stack;

typedef enum e_bool
{
	FALSE,
	TRUE
}					t_bool;

void				do_swap(t_stack **stack, t_bool print);
void				do_push(t_stack **to, t_stack **from);
void				do_rotate(t_stack **stack, t_bool print);
void				do_reverse_rotate(t_stack **stack, t_bool print);
void				do_both_swap(t_stack **a, t_stack **b);
void				do_both_rotate(t_stack **a, t_stack **b, t_bool reverse);

int					stack_len(t_stack *stack);
t_stack				*create_stack(int count, char **nums, char tag);
void				free_stack(t_stack **stack);
t_stack				*push_bottom(t_stack **stack, char tag);
t_stack				*find_last(t_stack *stack);

t_bool				set_node_num(char *num, t_stack *node);
t_stack				*find_min(t_stack *stack, t_stack *bottom);
t_stack				*find_max(t_stack *stack, t_stack *top);
t_stack				*find_mid(t_stack *stack);

void				set_target(t_stack *from, t_stack *to);
void				set_cost(t_stack *stack);
void				set_total_cost(t_stack *stack_a, t_stack *stack_b);

int					find_cost(t_stack *stack, t_stack *to_top);
t_stack				*find_target(t_stack *target_stack, t_stack *to_push);
int					find_total_cost(int cost_a, int cost_b);
t_stack				*find_cheapest(t_stack *stack);

void				top_node(t_stack *node, t_stack **stack);
void				total_rotate(t_stack *goal, t_stack **a, t_stack **b,
						t_bool reverse);
void				total_top_node(t_stack *goal, t_stack **a, t_stack **b);

void				push_a_to_b(t_stack **a, t_stack **b);
void				push_b_to_a(t_stack **a, t_stack **b);
void				sort_three(t_stack **stack);
void				sort_stack(t_stack **a, t_stack **b);

t_bool				stack_contains(int number, t_stack **stack);
t_bool				is_sorted(int smallest, t_stack *stack);

#endif