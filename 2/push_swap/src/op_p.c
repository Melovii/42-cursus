#include "push_swap.h"

// * Pushes from B to A
void	pa(t_liist **stack_a, t_liist **stack_b)
{
	t_liist	*push_b;

	if (!*stack_a)
		return ;
	push_b = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
	*stack_a = *stack_b;
	*stack_b = push_b;
	write(1, "pa\n", 3);
}

// * Pushes from A to B
void	pb(t_liist **stack_a, t_liist **stack_b)
{
	t_liist	*push_a;

	if (!*stack_b)
		return ;
	push_a = (*stack_a)->next;
	(*stack_a)->next = (*stack_b);
	*stack_b = *stack_a;
	*stack_a = push_a;
	write(1, "pb\n", 3);
}
