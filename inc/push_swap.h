#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	char			tag;
	int				value;
	int				size;
	struct s_stack	*next;
}					t_stack;

typedef enum e_bool
{
	false,
	true
}					t_bool;

void				do_swap(t_stack **stack, t_bool print);
void				do_push(t_stack **from, t_stack **to);
void				do_rotate(t_stack **stack, t_bool print);
void				do_reverse_rotate(t_stack **stack, t_bool print);
int					is_number(const char *str);
int					parse_arguments(int argc, char **argv, t_stack **a);
void				free_stack(t_stack **stack);
int					is_sorted(t_stack *stack);
void				sort_stack(t_stack **a, t_stack **b);
void				sort_three(t_stack **a);
void				sort_large(t_stack **a, t_stack **b);

#endif