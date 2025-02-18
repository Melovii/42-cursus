#include "../so_long.h"

// * Increases the player's position (up and right)
void	increase_pos()
{
	// TODO: DO SHIT
}

// * Decreases the player's position (down and left)
void	decrease_pos()
{
	// TODO: DO SHIT
}

// * Placeholder function to move the player (currently does nothing)
void	move_player(t_vars *vars)
{
	(void)vars;
	// TODO: DO SHIT
}

// * Placeholder game loop function (currently does nothing)
int	gameloop(t_vars *vars)
{
	(void)vars;
	// TODO: DO SHIT
	return (1);
}

// TODO: refactor code into using correct numbers (remove unused ones too)
// * Handles exit conditions based on error codes and sets failure state in the game
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
