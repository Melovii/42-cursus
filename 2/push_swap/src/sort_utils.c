#include "push_swap.h"

// * Checks if the list is sorted in ascending order
int	is_sorted(t_list **stack1)
{
	t_list	*tmp;

	tmp = *stack1;
	while (tmp && tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

// * Checks if list is sorted in descending order.
int	is_rev_sorted(t_swap *tab)
{
	t_list	*tmp;

	tmp = tab->stack_a;
	while (tmp->next)
	{
		if (tmp->content < tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

// * Checks if the list is sorted and if its size matches the given count.
int	lst_valid(t_list **stack1, int count)
{
	int	len;

	len = ft_lstsize(*stack1);
	if (len != count)
		return (0);
	if (is_sorted(stack1) == 0)
		return (0);
	return (1);
}

// * Finds minimum element in the list.
t_list	*find_min_lst(t_list **stack)
{
	t_list	*min;
	t_list	*tmp;

	min = *stack;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->content < min->content)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

// * Finds maximum element in the list.
t_list	*find_max_lst(t_list **stack)
{
	t_list	*max;
	t_list	*tmp;

	max = *stack;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->content > max->content)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}
