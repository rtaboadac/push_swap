#include "push_swap.h"

void	do_both_swap(t_stack **a, t_stack **b)
{
	do_swap(a, FALSE);
	do_swap(b, FALSE);
	printf("ss\n");
}

void	do_both_rotate(t_stack **a, t_stack **b, t_bool reverse)
{
	if (reverse)
	{
		do_reverse_rotate(a, FALSE);
		do_reverse_rotate(b, FALSE);
		printf("rrr\n");
	}
	else
	{
		do_rotate(a, FALSE);
		do_rotate(b, FALSE);
		printf("rr\n");
	}
}
