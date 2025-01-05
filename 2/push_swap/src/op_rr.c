#include "push_swap.h"

static void	ft_rr(t_liist **stack)
{
	t_liist *tail;
	t_liist *tmp;

	if (!(*stack) || !((*stack)->next))
		return ;
	tmp = *stack;
	tail = ft_lstlast(*stack);
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	tail->next = tmp;
	(*stack)->next = NULL;
	*stack = tail;
}

// * Reverse rotate stack A
void	rra(t_liist *stack_a)
{
	ft_rr(stack_a);
	write(1, "rra\n", 4);
}

// * Reverse rotate stack B
void	rrb(t_liist *stack_b)
{
	ft_rr(stack_b);
	write(1, "rrb\n", 4);
}

// * Does both rra and rrb
void	rrr(t_liist *stack_a, t_liist *stack_b)
{
	ft_rr(stack_a);
	ft_rr(stack_b);
	write(1, "rrr\n", 4);
}