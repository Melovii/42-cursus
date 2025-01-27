#include "push_swap.h"

// * Frees the stack
void free_stack(t_list **stack)
{
    t_list *tmp;

    if (!stack || !*stack)
        return;
    while (*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
    *stack = NULL;
}

// * Frees the args array created by ft_split
void free_args(char **args)
{
    int i = 0;

    if (!args)
        return;
    while (args[i])
    {
        free(args[i]);
        i++;
    }
    free(args);
}

//  * Frees the t_swap structure
void free_tab(t_swap *tab)
{
    if (!tab)
        return;
    free_stack(&(tab->stack_a));
    free_stack(&(tab->stack_b));
    free(tab);
}

// * Validates a number against specific rules and checks for duplicates in the list
int	ft_check(t_list *lst, int n, char *nbr)
{
	t_list	*tmp;
	int		i;

	tmp = lst;
	i = 0;
	while (nbr[i])
	{
		if (!(((nbr[i] == '-' || nbr[i] == '+') && ft_isdigit(nbr[i + 1])
					&& (i == 0 || !ft_isdigit(nbr[i - 1])) )
				|| ft_isdigit(nbr[i])))
			return (0);
		i++;
	}
	while (tmp)
	{
		if (tmp->content == n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

// * Processes a single argument, performs validation, and adds it to the list
t_list	*process_argument(char *arg, t_list **res)
{
	t_list	*tmp;
	long	nbr;

	nbr = ft_atoi(arg);
	if (nbr > INT_MAX || nbr < INT_MIN || ft_check(*res, nbr, arg) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(res); // Free allocated nodes before returning
		return (NULL);
	}
	tmp = ft_lstnew(nbr);
	if (!tmp)
	{
		ft_putstr_fd("Error\n", 2);
		free_stack(res); // Free allocated nodes before returning
		return (NULL);
	}
	ft_lstadd_back(res, tmp);
	tmp->index = -1;
	return (*res);
}
