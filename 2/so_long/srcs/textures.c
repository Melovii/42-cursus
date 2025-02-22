#include "../so_long.h"

void	set_tex(char *path, t_vars *vars, t_img *tex)
{
	const int	fd = open(path, O_RDONLY, 777);

	if (fd < 0)
	{
		ft_putstr_fd("Error:\n=> Foolish image path!\n", 2);
		exit(0);
	}
	tex->img = mlx_xpm_file_to_image(vars->mlx, path, &vars->tex->width,
			&vars->tex->height);
	if (!tex->img)
	{
		ft_exit("Error\n=> Can't load texture:", vars, FAILURE);
	}
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpx, &tex->line_len,
			&tex->endian);
	if (tex->addr == NULL)
	{
		ft_exit("Error: Failed to get texture address", vars, 1);
	}
}

void	tex_all(t_vars *vars)
{
	set_tex(TEX_WALL, vars, &vars->tex[0]);
	set_tex(TEX_BLANK, vars, &vars->tex[1]);
	set_tex(TEX_PLAYER, vars, &vars->tex[2]);
	set_tex(TEX_COIN, vars, &vars->tex[3]);
	set_tex(TEX_EXIT, vars, &vars->tex[4]);
}
