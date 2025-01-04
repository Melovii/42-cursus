#include "push_swap.h"

static void	ft_s(t_liist **stack)
{
	t_liist	*tmp;

	if (!(*stack) || !((*stack)->next))
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

// * Swaps top two values in stack A
void	sa(t_liist** stack_a)
{
	ft_s(stack_a);
	write(1, "sa\n", 3);
}

// * Swaps top two values in stack A
void	sb(t_liist** stack_b)
{
	ft_s(stack_b);
	write(1, "sb\n", 3);
}

// * Does both sa and sb
void	ss(t_liist** stack_a, t_liist** stack_b)
{
	ft_s(stack_a);
	ft_s(stack_b);
	write(1, "ss\n", 3);
}
