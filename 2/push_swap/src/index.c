#include "push_swap.h"

// * Finds smallest content value in a given list
int	find_min(t_liist *lst)
{
	t_liist		*tmp;
	long int	min;

	min = LONG_MAX; // ? why assign to largest long?
	tmp = lst;
	while (tmp)
	{
		if (tmp->index == -1 && tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

// * Replaces the index of the node that holds given value with a new matching content value
void	replace_index(t_liist *lst, int value, int new_value)
{
	t_liist	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->index == -1 && tmp->content == value)
			break ;
		tmp = tmp->next;
	}
	tmp->index = new_value;
}

// * Adds index values to each node based on their content in ascending order
void	add_index(t_liist *lst)
{
	int	len;
	int	min;
	int	i;

	i = 0;
	len = ft_lstsize(lst);
	while (i < len)
	{
		min = find_min(lst);
		replace_index(lst, min, i);
		i++;
	}
}
