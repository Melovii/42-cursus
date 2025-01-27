#include "push_swap.h"

// Begin sorting the stack by dividing elements based on their index compared to the midpoint
void	begin_sorting(t_list **stack1, t_list **stack2, t_push *push, int count)
{
	int	i;

	i = -1;
	while (++i < count) // Process each element up to the given count
	{
		if ((*stack1)->index <= push->mid) // If the element index is less than or equal to the midpoint, push to stack2
			pb(stack1, stack2);
		else
		{
			// If stack2 has more than one element and the current index is less than half of the midpoint, rotate both stacks
			if (ft_lstsize(*stack2) > 1 && (*stack2)->index < (push->mid / 2))
				rr(stack1, stack2);
			else
				ra(stack1); // Otherwise, rotate stack1
		}
	}
	// Update the maximum, midpoint, and flag for the next iteration
	push->max = push->mid;
	push->mid = (push->max - push->next) / 2 + push->next;
	push->flag++;
}

// Find and process the next element in sorted order
void	find_next(t_list **stack1, t_list **stack2, t_push *push)
{
	// If the top element of stack2 is the next element in sorted order, push it to stack1
	if (ft_lstsize(*stack2) > 0 && ((*stack2)->index == push->next))
		pa(stack1, stack2);
	// If the top element of stack1 is the next element, rotate it and mark it as sorted
	else if ((*stack1)->index == push->next)
	{
		(*stack1)->flag = -1;
		ra(stack1);
		push->next++;
	}
	// If the last element of stack2 is the next element, reverse rotate stack2
	else if ((ft_lstsize(*stack2)) > 2 && ft_lstlast(*stack2)->index == push->next)
		rrb(stack2);
	// If the second element of stack1 is the next element, swap the top two elements of stack1
	else if ((*stack1)->next->index == push->next)
		sa(stack1);
	// If the top elements of both stacks are consecutive in sorted order, swap both
	else if ((ft_lstsize(*stack1)) > 1 && ((*stack1)->next->index == push->next)
		&& ((*stack2)->next->index == push->next + 1))
		ss(stack1, stack2);
	else
		return; // If no condition is met, exit the function
	find_next(stack1, stack2, push); // Recursively process the next element
}

// Push elements from stack2 to stack1 based on sorting logic
void	quick_a(t_list **stack1, t_list **stack2, t_push *push)
{
	int	count_b;
	int	i;

	i = -1;
	count_b = ft_lstsize(*stack2); // Count the number of elements in stack2
	while (ft_lstsize(*stack2) && ++i < count_b)
	{
		// If the top element of stack2 is the next element, process it
		if ((*stack2)->index == push->next)
			find_next(stack1, stack2, push);
		// If the element index is greater than or equal to the midpoint, push it to stack1
		else if ((*stack2)->index >= push->mid)
		{
			(*stack2)->flag = push->flag; // Mark it with the current flag
			pa(stack1, stack2);
		}
		// If the element index is less than the midpoint, rotate stack2
		else if ((*stack2)->index < push->mid)
			rb(stack2);
	}
	// Update the maximum, midpoint, and flag for the next iteration
	push->max = push->mid;
	push->mid = (push->max - push->next) / 2 + push->next;
	push->flag++;
}

// Push elements from stack1 to stack2 based on sorting logic
void	quick_b(t_list **stack1, t_list **stack2, t_push *push)
{
	int	now_flag;

	now_flag = (*stack1)->flag; // Store the current flag of the top element
	if ((*stack1)->flag != 0)
	{
		// Push elements to stack2 until the flag changes
		while ((*stack1)->flag == now_flag)
		{
			if ((*stack1)->index != push->next)
				pb(stack1, stack2);
			find_next(stack1, stack2, push);
		}
	}
	else if ((*stack1)->flag == 0)
	{
		// Push elements to stack2 until the flag becomes -1
		while ((*stack1)->flag != -1)
		{
			if ((*stack1)->index != push->next)
				pb(stack1, stack2);
			find_next(stack1, stack2, push);
		}
	}
	// Update the maximum and midpoint if stack2 is not empty
	if (ft_lstsize(*stack2))
		push->max = (find_max_lst(stack2))->index;
	push->mid = (push->max - push->next) / 2 + push->next;
}

// Perform the quick sort algorithm using stack1 and stack2
void	quick_sort(t_list **stack1, t_list **stack2, int count)
{
	t_push	push;

	// Initialize the sorting helper structure
	push.next = find_min_lst(stack1)->index; // The next element to be sorted
	push.max = find_max_lst(stack1)->index; // The maximum index in stack1
	push.mid = push.max / 2 + push.next;    // The midpoint of the current range
	push.flag = 0;                         // Initialize the flag counter
	begin_sorting(stack1, stack2, &push, count); // Begin sorting stack1 into stack2
	while (!(lst_valid(stack1, count)))    // Continue until stack1 is fully sorted
	{
		if (ft_lstsize(*stack2) == 0)      // If stack2 is empty, process stack1
			quick_b(stack1, stack2, &push);
		else                              // Otherwise, process stack2
			quick_a(stack1, stack2, &push);
	}
}
