#include "../so_long.h"

// * Initialises key states
t_key   *init_keys(void)
{
	t_key   *keys;

	keys = malloc(sizeof(t_key));
	if (!keys)
		return (NULL);
	keys->dir = 0;
	keys->w = 0;
	keys->a = 0;
	keys->s = 0;
	keys->d = 0;
	return (keys);
}

// * Handle key press events
int	key_press(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC || keycode == KEY_EXIT) // ! good to keep them separate or? check it out!
		ft_exit(NULL, vars, SUCCESS);
	else if (keycode == KEY_W && vars->key->w == 0)
		vars->key->w = 1;
	else if (keycode == KEY_A && vars->key->a == 0)
		vars->key->a = 1;
	else if (keycode == KEY_S && vars->key->s == 0)
		vars->key->s = 1;
	else if (keycode == KEY_D && vars->key->d == 0)
		vars->key->d = 1;
	return (1);
}

// * Handle key release events
int	key_release(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC || keycode == KEY_EXIT) // ! good to keep them separate or? check it out!
		ft_exit(NULL, vars, SUCCESS); // also wait why am I doin this twice..?
	else if (keycode == KEY_W && vars->key->w == 1)
		vars->key->w = 0;
	else if (keycode == KEY_A && vars->key->a == 1)
		vars->key->a = 0;
	else if (keycode == KEY_S && vars->key->s == 1)
		vars->key->s = 0;
	else if (keycode == KEY_D && vars->key->d == 1)
		vars->key->d = 0;
	return (1);
}

// * Handle game events
int	key_event(t_vars *vars)
{
	if (vars->coin == 0 && vars->map[vars->pos->y][vars->pos->x] == 'E')
		ft_exit("YOU WON WOHOO!\n", vars, SUCCESS);
	else
		move_player(vars); // process player movement.
	return (1);
}
