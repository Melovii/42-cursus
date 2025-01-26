#include "push_swap.h"

// * Checks if the list is sorted in ascending order
int	is_sorted(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
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
	while (tmp)
	{
		if (tmp->content < tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

// * Checks if the list is sorted and if its size matches the given count.
int	lst_valid(t_list **stack, int count)
{
	int	len;

	len = ft_lstsize(*stack);
	if (len != count)
		return (0);
	if (is_sorted(stack) == 0)
		return (0);
	return (1);
}

// * Finds minimum element in the list.
t_list	*find_min_lst(t_list **stack)
{
	t_list	*tmp;
	t_list	*min;

	tmp = *stack;
	min = *stack;
	while (tmp)
	{
		if (min->content > tmp->content)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

// * Finds maximum element in the list.
t_list	*find_max_lst(t_list **stack)
{
	t_list	*tmp;
	t_list	*max;

	tmp = *stack;
	max = *stack;
	while (tmp)
	{
		if (max->content < tmp->content)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}
