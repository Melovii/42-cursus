#include "push_swap.h"

static void	ft_s(t_list **stack)
{
	t_list	*tmp;

	if (!(*stack) || !((*stack)->next))
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

// * Swaps top two values in stack A
void	sa(t_list** stack_a)
{
	ft_s(stack_a);
	write(1, "sa\n", 3);
}

// * Swaps top two values in stack A
void	sb(t_list** stack_b)
{
	ft_s(stack_b);
	write(1, "sb\n", 3);
}

// * Does both sa and sb
void	ss(t_list** stack_a, t_list** stack_b)
{
	ft_s(stack_a);
	ft_s(stack_b);
	write(1, "ss\n", 3);
}
