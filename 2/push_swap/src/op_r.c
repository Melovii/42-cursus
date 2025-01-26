#include "push_swap.h"

static void	ft_r(t_list **stack)
{
	t_list	*head;

	head = *stack;
	if (!(*stack) || !((*stack)->next))
		return ;
	*stack = head->next;
	head->next = NULL;
	ft_lstlast(*stack)->next = head;
}

// * Rotates stack A (Shifts all elements of stack A from bottom to top)
void	ra(t_list **stack_a)
{
	ft_r(stack_a);
	write(1, "ra\n", 3);
}

// * Rotates stack B (Shifts all elements of stack B from bottom to top)
void	rb(t_list **stack_b)
{
	ft_r(stack_b);
	write(1, "rb\n", 3);
}

// * Does both ra and rb
void	rr(t_list **stack_a, t_list **stack_b)
{
	ft_r(stack_a);
	ft_r(stack_b);
	write(1, "rr\n", 3);
}
