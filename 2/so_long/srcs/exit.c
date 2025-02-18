#include "../so_long.h"

void	ft_free(void *vars)
{
	if (vars)
		free(vars);
	vars = NULL;
}

// ! CHANGED IMPLEMENTATION
void	destroy_img(t_vars *vars)
{
    int	i;

    if (vars->mlx)
    {
        if (vars->img && vars->img->img)
        {
            mlx_destroy_image(vars->mlx, vars->img->img);
            ft_free(vars->img);
        }
        i = 0;
        while (i < 5) // loop through the number of textures
        {
            if (vars->tex[i].img) // Check if the image was loaded before destroying it
              mlx_destroy_image(vars->mlx, vars->tex[i].img);
            i++;
        }
        mlx_destroy_window(vars->mlx, vars->win);
        mlx_destroy_display(vars->mlx);
        ft_free(vars->mlx);
    }
}

void	free_vars(t_vars *vars)
{
	int	i;

	if (vars)
	{
		destroy_img(vars);
		if (vars->key)
			ft_free(vars->key);
		if (vars->pos)
			ft_free(vars->pos);
		i = 0;
		if (vars->map)
		{
			while (vars->map[i])
				ft_free(vars->map[i++]);
			ft_free(vars->map);
		}
		ft_free(vars);
	}
}

int	ft_exit(char *msg, t_vars *vars, int ret)
{
	if (msg)
		ft_putstr_fd(msg, 2);
	free_vars(vars);
	exit(ret);
}
