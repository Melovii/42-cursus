#include "../so_long.h"

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

void	move_player(t_vars *vars)
{
	if (vars->key->w)
	{
		process_movement(vars, vars->pos->x, vars->pos->y - 1);
		vars->key->w = 0;
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

int	gameloop(t_vars *vars)
{
	draw_map(vars);
	draw_player(vars);
	key_event(vars);
	return (1);
}

int	ft_exitc(int set, t_vars *vars, int ret)
{
	if (!set)
	{
		if (!vars->fail)
			return (0);
		else if (vars->fail == 1)
			ft_exit("Error\n=> Foolish map\n", vars, ret);
		else if (vars->fail == 2)
			ft_exit("Error\n=> Foolish char in map\n", vars, ret);
		else if (vars->fail == 3)
			ft_exit("Error\n=> Map does not exist\n", vars, ret);
		else if (vars->fail == 4)
			ft_exit("Error\n=> Map error\n", vars, ret);
	}
	else
	{
		if (!vars->fail)
			vars->fail = set;
	}
	return (0);
}
