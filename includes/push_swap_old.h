/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:50:13 by rtaboada          #+#    #+#             */
/*   Updated: 2024/09/01 20:02:34 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/ft_printf/ft_printf.h"
# include "../lib/libft/libft.h"
# include <limits.h>

typedef enum e_bool
{
	FALSE,
	TRUE
}					t_bool;

typedef struct s_stack

{
	int				nbr;
	int				index;
	int				push_cost;
	t_bool			above_median;
	t_bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
	char			tag;
}					t_stack;

int					check_syntax(char *str_n);
int					check_duplicate(t_stack *a, int n);
void				free_stack(t_stack **stack);
void				free_errors(t_stack **a);

void				init_stack_a(t_stack **a, char **argv);

void				init_nodes_a(t_stack *a, t_stack *b);

void				init_nodes_b(t_stack *a, t_stack *b);

void				current_index(t_stack *stack);

void				set_cheapest(t_stack *stack);

t_stack				*get_cheapest(t_stack *stack);

void				pre_push(t_stack **s, t_stack *n);

int					stack_len(t_stack *stack);
t_stack				*find_last(t_stack *stack);
t_bool				stack_sorted(t_stack *stack);

t_stack				*find_min(t_stack *stack);
t_stack				*find_max(t_stack *stack);

void				do_swap(t_stack **stack, t_bool print);
void				do_push(t_stack **to, t_stack **from);
void				do_rotate(t_stack **stack, t_bool print);
void				do_reverse_rotate(t_stack **stack, t_bool print);
void				do_both_swap(t_stack **a, t_stack **b);
void				do_both_rotate(t_stack **a, t_stack **b, t_bool reverse);

void				set_cheapest(t_stack *stack);
void				cost_analysis(t_stack *a, t_stack *b);

void				sort_three(t_stack **a);
void				sort_stacks(t_stack **a, t_stack **b);

#endif