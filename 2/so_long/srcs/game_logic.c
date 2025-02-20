#include "../so_long.h"

// * Validates move, updates position, increments move count, collects coin
void	process_movement(t_vars *vars, int new_x, int new_y)
{
	if (vars->map[new_y][new_x] != '1')
	{
		vars->pos->x = new_x;
		vars->pos->y = new_y;
		vars->moves++;
		printf("Moves: %d\n", vars->moves);

		if (vars->map[vars->pos->y][vars->pos->x] == 'C')
		{
			vars->coin--;
			vars->map[vars->pos->y][vars->pos->x] = '0';
		}
	}
}

// * Moves the player based on key presses
void	move_player(t_vars *vars)
{
	if (vars->key->w)
	{
		process_movement(vars, vars->pos->x, vars->pos->y - 1);
		vars->key->w = 0; // Reset the key state
	}
	if (vars->key->a)
	{
		process_movement(vars, vars->pos->x - 1, vars->pos->y);
		vars->key->a = 0;
	}
	if (vars->key->s)
	{
		process_movement(vars, vars->pos->x, vars->pos->y + 1);
		vars->key->s = 0;
	}
	if (vars->key->d)
	{
	 	process_movement(vars, vars->pos->x + 1, vars->pos->y);
	 	vars->key->d = 0;
	}
}

// * Game loop function
int gameloop(t_vars *vars)
{
    draw_map(vars);
    draw_player(vars);
    key_event(vars);
    return (1);
}

// * Handles exit conditions based on error codes and sets failure state in the game
int ft_exitc(int set, t_vars *vars, int ret)
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
    {
        if (!vars->fail)
            vars->fail = set;
    }
    return (0);
}