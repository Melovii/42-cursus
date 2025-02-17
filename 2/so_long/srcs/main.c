#include "../so_long.h"

// * Handle the quit event
int	quit_event(t_vars *vars)
{
	ft_exit(NULL, vars, SUCCESS);
	mlx_do_key_autorepeaton(vars->mlx); // ! wtf is this???
	return (0);
}

// * Initialises the game program
void	init_program(t_vars *vars)
{
	// vars->mlx = mlx_init(); // ?! WHY IS THIS NOT NECESSARY HERE BUT NECESSARY IN MAIN !?
	vars->img->img = mlx_new_image(vars->mlx,
		100 * vars->map_width, 100 * vars->map_height);
	if (!vars->img->img)
		ft_exit("Error\n=> Canʻt create image!", vars, FAILURE); // ? check norm might be long lol

	vars->win = mlx_new_window(vars->mlx,
		100 * vars->map_width, 100 * vars->map_height, TITLE); // ? check norm for this shit lmfao
	if (!vars->win)
		ft_exit("Error\n=> Canʻt create window!", vars, FAILURE);

	tex_all(vars); // TODO: create tex_all function
	vars->img->addr = mlx_get_data_addr(vars->img->img,
					&vars->img->bpx, &vars->img->line_len, vars->img->endian); // ? check fucking norm?
	if (!vars->img->addr)
		ft_exit("Error\n=> Canʻt get image address!", vars, FAILURE); // ? I think no need...? double check lol

		vars->img->width = 1000; // why
		vars->img->height = 1000; // why
		vars->moves = 0;

		mlx_hook(vars->win, 2, 1L << 0, key_press, vars); // yeah like why is this not enough
		mlx_hook(vars->win, 3, 1L << 1, key_release, vars); // wtf is dis
		mlx_hook(vars->win, KEY_EXIT, 1L << 2, quit_event, vars); // uhm ok but why?
		mlx_loop_hook(vars->mlx, event_loop, vars); // TODO: create event_loop / game_loop function!
		mlx_loop(vars->mlx);
}

// * Initializes the game, checks arguments, allocates memory, and sets up MLX
int	main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc != 2)
		ft_exit("Error\n=> Invalid arguments!\n", NULL, FAILURE);

	vars = ft_calloc(sizeof(t_vars), 1); // ! Explain why I used ft_calloc and not malloc here
	if (!vars)
		ft_exit("Error\n=> Can't malloc (vars)!\n", vars, FAILURE);

	vars->pos = malloc(sizeof(t_pos));
	if (!vars->pos)
		ft_exit("Error\n=> Can't malloc (pos)!\n", vars, FAILURE);

	vars->key = init_key();
	if (!vars->key)
		ft_exit("Error\n=> Can't malloc (key)!\n", vars, FAILURE);

	parse_map(argv[1], vars);

	vars->img = malloc(sizeof(t_img));
	if (!vars->img)
		ft_exit("Error\n=> Can't malloc (img)!\n", vars, FAILURE);

	vars->mlx = mlx_init();	// ! WHY ADD IT HERE AND NOT IN INIT_PROGRAM() ?
	if (!vars->mlx)
		ft_exit("Error\n=> Can't init mlx!\n", vars, FAILURE);

	init_program(vars);
	return (0);
}
