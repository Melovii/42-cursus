#include <stdio.h>
#include "../so_long.h"

// * Initializes the game, checks arguments, allocates memory, and sets up MLX
int	main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc != 2)
		ft_exit("Error\n Bad argument!\n", NULL, FAILURE);
	vars = ft_calloc(sizeof(t_vars), 1); // ! Explain why I used ft_calloc and not malloc here
	if (!vars)
		ft_exit("Error\n Can't malloc (vars)!\n", vars, FAILURE);
	vars->pos = malloc(sizeof(t_pos));
	if (!vars->pos)
		ft_exit("Error\n Can't malloc (pos)!\n", vars, FAILURE);
	vars->key = init_key();	// TODO: init_key function
	if (!vars->key)
		ft_exit("Error\n Can't malloc (key)!\n", vars, FAILURE);
	parsing(argv[1], vars);	// TODO: parsing function
	vars->img = malloc(sizeof(t_img));
	if (!vars->img)
		ft_exit("Error\n Can't malloc (img)!\n", vars, FAILURE);
	vars->mlx = mlx_init();	// TODO: init_mlx function
	if (!vars->mlx)
		ft_exit("Error\n Can't init mlx!\n", vars, FAILURE);
	init_program(vars);	// TODO: init_program function
	return (0);
}
