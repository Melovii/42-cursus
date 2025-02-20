#include "../so_long.h"

// * Loads an XPM image from a file path into a t_img struct and assigns its properties
void    set_tex(char *path, t_vars *vars, t_img *tex)
{
	const int	fd = open(path, O_RDONLY, 777); // ! wtf can I even do this..?

	if (fd < 0)
	{
		ft_putstr_fd("Error:\n=> Invalid image path!\n", 2);
		exit(0);
	}
	tex->img = mlx_xpm_file_to_image(vars->mlx, path, &vars->tex->width, &vars->tex->height);
    if (!tex->img)
	{
        ft_exit("Error\n=> Can't load texture:", vars, FAILURE); // ! change this into a default msg without path (cause can't add \n ffs)
	}
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpx, &tex->line_len, &tex->endian); // ! why..?
	if (tex->addr == NULL)
	{
		ft_exit("Error: Failed to get texture address", vars, 1);
	}
}

// * Loads textures into the tex[] array for sprites
void tex_all(t_vars *vars)
{
    set_tex(TEX_WALL, vars, &vars->tex[0]);    // Index 0: Wall
    set_tex(TEX_BLANK, vars, &vars->tex[1]);   // Index 1: Blank
    set_tex(TEX_PLAYER, vars, &vars->tex[2]);  // Index 2: Player
    set_tex(TEX_COIN, vars, &vars->tex[3]);    // Index 3: Coin
    set_tex(TEX_EXIT, vars, &vars->tex[4]);    // Index 4: Exit
}