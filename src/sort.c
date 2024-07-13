#include "push_swap.h"

void	sort_stack(t_stack **a, t_stack **b)
{
	if ((*a)->size == 2 && !is_sorted(*a))
		do_swap(a, true);
	else if ((*a)->size == 3)
		sort_three(a);
	else if ((*a)->size > 3)
		sort_large(a, b);
}

void	sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && third > first)
		do_swap(a, true);
	else if (first > second && second > third && third < first)
	{
		do_swap(a, true);
		do_reverse_rotate(a, true);
	}
	else if (first > second && second < third && third < first)
		do_rotate(a, true);
	else if (first < second && second > third && third > first)
	{
		do_swap(a, true);
		do_rotate(a, true);
	}
	else if (first < second && second > third && third < first)
		do_reverse_rotate(a, true);
}

void	sort_large(t_stack **a, t_stack **b)
{
	int	mid;

	mid = (*a)->size / 2;
	while ((*a)->size > mid)
	{
		pb(a, b);
	}
	sort_stack(a, b);
	sort_stack(b, a);
	while (*b)
	{
		do_push(b, a);
	}
}
