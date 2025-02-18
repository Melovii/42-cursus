#include "../so_long.h"

// * Loads an XPM image from a file path into a t_img struct and assigns its properties
void    set_tex(char *path, t_vars *vars, t_img *tex)
{
    tex->img = mlx_xpm_file_to_image(vars->mlx, path, &tex->width, &tex->height);
    if (!tex->img) {
		ft_putstr_fd("Error\n=> Can't load texture:", 2);
        ft_exit(path, vars, FAILURE); // ! change this into a default msg without path (cause can't add \n ffs)
    }
}

void	tex_all(t_vars *vars)
{
	// TODO: update tex[] array size (6 ?)
	set_tex(TEX_WALL, vars, &vars->tex[0]);
	set_tex(TEX_BLANK, vars, &vars->tex[1]);
	set_tex(TEX_PLAYER, vars, &vars->tex[2]);
	set_tex(TEX_COIN, vars, &vars->tex[3]);
	set_tex(TEX_EXIT, vars, &vars->tex[4]);
}
