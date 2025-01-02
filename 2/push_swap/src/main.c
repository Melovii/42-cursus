// main.c (Main Entry Point)
#include "push_swap.h"

int	ft_check(t_liist* lst, int n, char* nbr)
{
	t_liist*	tmp;
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

void	ft_init_stacks(int argc, char** argv)
{
	t_liist	*tmp;
	t_liist	*res;
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
			ft_puttr_fd("Error\n", 2);
			return (NULL);
		}
		tmp = ft_lstnew(nbr);
		ft_lstadd_back(&res, tmp);
		tmp->next = -1;
		i++;
	}
	return (res);
}

int	main(int argc, char** argv)
{
	// ! - The first argument should be at the top of the stack

/*
	initialize program by
	1. Checking if there's only one argument and exiting if true.
	2. Allocating memory for the `t_swap` struct to hold stacks and their sizes.
	3. Parsing input arguments (either from one or multiple arguments).
	4. Initializing `stack_a` using the parsed arguments.
	5. Initializing `stack_b` as empty.
	6. Calculating the sizes of both stacks.
	7. Assigning indexes to the elements in `stack_a`.
	8. Checking if `stack_a` is already sorted.
*/
}
