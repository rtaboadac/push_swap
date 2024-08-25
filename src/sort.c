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

void	sort_three(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	if (first > second && second < third)
		return (do_swap(stack, TRUE));
	if (first > second && second > third && third < first)
		return (do_swap(stack, TRUE), do_reverse_rotate(stack, TRUE));
	if (first > second && second < third && third < first)
		return (do_rotate(stack, TRUE));
	if (first < second && second > third && third > first)
		return (do_swap(stack, TRUE), do_rotate(stack, TRUE));
	if (first < second && second > third && third < first)
		return (do_reverse_rotate(stack, TRUE));
}

void	sort_five(t_stack **a, t_stack **b)
{

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
