#include "push_swap.h"

void	do_both_swap(t_stack **a, t_stack **b)
{
	do_swap(a, false);
	do_swap(b, false);
	printf("ss\n");
}

void	do_both_rotate(t_stack **a, t_stack **b, t_bool reverse)
{
	if (reverse)
	{
		do_reverse_rotate(a, false);
		do_reverse_rotate(b, false);
		printf("rrr\n");
	}
	else
	{
		do_rotate(a, false);
		do_rotate(b, false);
		printf("rr\n");
	}
}