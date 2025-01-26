#include "push_swap.h"

static void	ft_rr(t_list **stack)
{
	t_list	*tail;
	t_list	*tmp;
	t_list	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ; // Nothing to rotate
	
	tmp = *stack;
	tail = ft_lstlast(*stack);
	second_last = *stack;
	
	// Traverse to the second-last node
	while (second_last->next->next)
		second_last = second_last->next;
	
	// Move the last node to the top
	second_last->next = NULL;
	tail->next = tmp;
	*stack = tail; // Update the head of the stack
}


// * Reverse rotate stack A
void	rra(t_list **stack_a)
{
	ft_rr(stack_a);
	write(1, "rra\n", 4);
}

// * Reverse rotate stack B
void	rrb(t_list **stack_b)
{
	ft_rr(stack_b);
	write(1, "rrb\n", 4);
}

// * Does both rra and rrb
void	rrr(t_list **stack_a, t_list **stack_b)
{
	ft_rr(stack_a);
	ft_rr(stack_b);
	write(1, "rrr\n", 4);
}