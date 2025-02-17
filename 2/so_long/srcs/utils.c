#include "../so_long.h"

// TODO: refactor code into using correct numbers (remove unused ones too)
int	ft_exitc(int set, t_vars *vars, int ret)
{
	if (!set)
	{
		if (!vars->fail)
			return (0);
		else if (vars->fail == 1)
			ft_exit("Error\n=> Invalid map\n", vars, ret);
		else if (vars->fail == 2)
			ft_exit("Error\n=> Invalid char in map\n", vars, ret);
		else if (vars->fail == 4)
			ft_exit("Error\n=> Invalid map\n", vars, ret);
		else if (vars->fail == 5)
			ft_exit("Error\n=> Map does not exist\n", vars, ret);
		else if (vars->fail == 6)
			ft_exit("Error\n=> Map error\n", vars, ret);
	}
	else
		if (!vars->fail)
			vars->fail = set;
	return (0);
}
