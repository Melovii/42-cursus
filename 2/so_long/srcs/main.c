#include "../so_long.h"

int	quit_event(t_vars *vars)
{
	ft_exit(NULL, vars, SUCCESS);
	mlx_do_key_autorepeaton(vars->mlx);
	return (0);
}

void	init_program(t_vars *vars)
{
	vars->img->img = mlx_new_image(vars->mlx, 64 * vars->map_width,
			64 * vars->map_height);
	if (!vars->img->img)
		ft_exit("Error\n=> Canʻt create image!", vars, FAILURE);
	vars->win = mlx_new_window(vars->mlx, 64 * vars->map_width,
			64 * vars->map_height, TITLE);
	if (!vars->win)
		ft_exit("Error\n=> Canʻt create window!", vars, FAILURE);
	tex_all(vars);
	vars->img->addr = mlx_get_data_addr(vars->img->img, &vars->img->bpx,
			&vars->img->line_len, &vars->img->endian);
	if (!vars->img->addr)
	{
		ft_exit("Error\n=> Canʻt get image address!", vars, FAILURE);
	}
	vars->img->width = 1000;
	vars->img->height = 1000;
	vars->moves = 0;
	mlx_hook(vars->win, 2, 1L << 0, key_press, vars);
	mlx_hook(vars->win, 3, 1L << 1, key_release, vars);
	mlx_hook(vars->win, KEY_EXIT, 1L << 2, quit_event, vars);
	mlx_loop_hook(vars->mlx, gameloop, vars);
	mlx_loop(vars->mlx);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc != 2)
		ft_exit("Error\n=> Foolish arguments!\n", NULL, FAILURE);
	vars = ft_calloc(sizeof(t_vars), 1);
	if (!vars)
		ft_exit("Error\n=> Can't malloc (vars)!\n", vars, FAILURE);
	vars->pos = malloc(sizeof(t_pos));
	if (!vars->pos)
		ft_exit("Error\n=> Can't malloc (pos)!\n", vars, FAILURE);
	vars->key = init_keys();
	if (!vars->key)
		ft_exit("Error\n=> Can't malloc (key)!\n", vars, FAILURE);
	parse_map(argv[1], vars);
	vars->img = malloc(sizeof(t_img));
	if (!vars->img)
		ft_exit("Error\n=> Can't malloc (img)!\n", vars, FAILURE);
	vars->mlx = mlx_init();
	if (!vars->mlx)
		ft_exit("Error\n=> Can't init mlx!\n", vars, FAILURE);
	init_program(vars);
	return (0);
}
