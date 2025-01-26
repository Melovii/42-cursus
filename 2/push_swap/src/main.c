// main.c (Main Entry Point)
#include "push_swap.h"

int	ft_check(t_list* lst, int n, char* nbr)
{
	t_list*	tmp;
	int			i;

	tmp = lst;
	i = 0;
	while (nbr[i])
	{
		if (!((nbr[i] == '-' || nbr[i] == '+') && (ft_isdigit(nbr[i + 1]))
				&& (!ft_isdigit(nbr[i - 1]))))
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

t_list	*ft_init_stacks(int argc, char** argv)
{
	t_list	*tmp;
	t_list	*res;
	long	nbr;
	int		i;

	if (argc == 2)
		i = 0;
	else
		i = 1;
	res = NULL;
	while (argv[i])
	{
		nbr = ft_atoi(argv[i]);
		if (nbr < INT_MIN || nbr > INT_MAX || ft_check(res, nbr, argv[i]) == 0)
		{
			ft_putstr_fd("Error\n", 2);
			return (NULL);
		}
		tmp = ft_lstnew(nbr);
		ft_lstadd_back(&res, tmp);
		// tmp->next = -1;
		tmp->next = NULL;
		i++;
	}
	return (res);
}

// ! - The first argument should be at the top of the stack
int	main(int argc, char** argv)
{
	t_swap	*tab;
	char	**args;

	if (argc == 1)
		return (0);
	tab = malloc(sizeof(t_swap));
	if (!tab)
		return (-1);
	if (argc == 2)
		args = ft_split(argv[1], ' '); // * first argument could be the only given argument as a string
	else
		args = argv;
	tab->stack_a = ft_init_stacks(argc, args);
	if (!tab->stack_a) // ? does this need double parntheses?
		return (-1);
	tab->stack_b = NULL;
	tab->a_size = ft_lstsize(tab->stack_a);
	tab->b_size = ft_lstsize(tab->stack_b);
	add_index(tab->stack_a); // TODO: Implement this function to add indexes to stack_a
	check_sort(tab); // TODO: Implement this function to determine size of stack_a and applies appropriate sorting alg
}
