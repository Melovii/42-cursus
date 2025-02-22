#include "../so_long.h"

t_key	*init_keys(void)
{
	t_key	*keys;

	keys = malloc(sizeof(t_key));
	if (!keys)
		return (NULL);
	keys->w = 0;
	keys->a = 0;
	keys->s = 0;
	keys->d = 0;
	return (keys);
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC || keycode == KEY_EXIT)
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

int	key_release(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC || keycode == KEY_EXIT)
		ft_exit(NULL, vars, SUCCESS);
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

int	key_event(t_vars *vars)
{
	if (vars->coin == 0 && vars->map[vars->pos->y][vars->pos->x] == 'E')
		ft_exit(MSG_WIN, vars, SUCCESS);
	else
		move_player(vars);
	return (1);
}
