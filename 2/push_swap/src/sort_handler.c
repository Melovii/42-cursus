#include "push_swap.h"

// * Sorts exactly 3 elements in stack_a in ascending order
// * assumes stack_a has exactly 3 elements
void	sort_3n(t_swap *tab)
{
	t_list	*last;

	if (is_sorted(&tab->stack_a)) // a > b > c
		return ;
	last = ft_lstlast(tab->stack_a);
	if (is_rev_sorted(tab)) // a < b < c
	{
		sa(&tab->stack_a);
		rra(&tab->stack_a);
	}

	// ? since there is a check for if it's sorted, the first and last else if's are for catching
	
	// Swap the first 2 elements if the 1st and 2nd elements are smaller than the last
	else if (tab->stack_a->content < last->content
		&& tab->stack_a->next->content < last->content) // a < c && b < c 
		sa(&tab->stack_a);
	
	// Rotate the stack to position smallest element at the top
	// if the 1st element is greater and 2nd is smaller than the last
	else if (tab->stack_a->content > last->content
		&& tab->stack_a->next->content < last->content) // a > c && b < c
		ra(&tab->stack_a);
	
	// Swap the first 2 elements then rotate 
	// if the 1st element is smaller and the 2nd element is greater than than the last
	else if (tab->stack_a->content < last->content
		&& tab->stack_a->next->content > last->content) // a < c && b > c
	{
		sa(&tab->stack_a);
		ra(&tab->stack_a);
	}

	// a > c && b > c
	else if (tab->stack_a->content > last->content
		&& tab->stack_a->next->content > last->content)
		rra(&tab->stack_a);
}

// * Sorts exactly 5 elements in stack_a in ascending order.
// * Uses stack_b as temporary storage for the two smallest elements.
void	sort_5n(t_swap	*tab)
{
	int	len;

	len = ft_lstsize(tab->stack_a);
	while (len--)
	{
		// If the top element has index 0 or 1 (smallest elements).
		if (tab->stack_a->index == 0 || tab->stack_a->index == 1)
			pb(&tab->stack_a, &tab->stack_b); // Push the smallest element to stack_b.
		else
			ra(&tab->stack_a); // Rotate stack_a to process the next element.
	}
	sort_3n(tab);
	// Push the two smallest elements back from stack_b to stack_a.
	pa(&tab->stack_a, &tab->stack_b);
	pa(&tab->stack_a, &tab->stack_b);
	if (tab->stack_a->content > tab->stack_a->next->content)
		sa(&tab->stack_a); // Swap the top two elements of stack_a if necessary to finalize sorting.
}

// * Checks size of stack A and calls appropriate sorting
void	sort_call(t_swap *tab)
{
	int	len;

	len = ft_lstsize(tab->stack_a);
	if (is_sorted(&tab->stack_a))
		return ;
	if (len == 2)
	{
		// Just a singular swap lol.
		if (tab->stack_a->content > tab->stack_a->next->content)
			sa(&tab->stack_a);
	}
	// Call the appropriate sorting function
	else if (len == 3)
		sort_3n(tab);
	else if (len == 5)
		sort_5n(tab);
	else
		quick_sort(&tab->stack_a, &tab->stack_b, ft_lstsize(tab->stack_a));
}
