// op3.c (Stack Operations - ra, rb, rr)
#include "push_swap.h"

static void	ft_r(t_liist **stack)
{
	t_liist *head;
	if (!(*stack) && !(*stack)->next)
		return ;
	head = *stack;
	*stack = head->next;
	head->next = NULL;
	ft_lstlast(*stack)->next = head;
}

// * Rotates stack A (Shifts all elements of stack A from bottom to top)
void	ra(t_liist **stack_a)
{
	ft_r(stack_a);
	write(1, "ra\n", 3);
}

// * Rotates stack B (Shifts all elements of stack B from bottom to top)
void	rb(t_liist **stack_b)
{
	ft_r(stack_b);
	write(1, "rb\n", 3);
}

// * Does both ra and rb
void	rr(t_liist **stack_a, t_liist **stack_b)
{
	ft_r(stack_a);
	ft_r(stack_b);
	write(1, "rr\n", 3);
}
