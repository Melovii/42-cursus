#include "../so_long.h"

// TODO: oh btw test if map that has no access to finish gives error or not lmfao
void draw_tile(t_vars *vars, int i, int x_index, int y_index)
{
    const double tile_width = 64;
    const double tile_height = 64;

    double x = x_index * tile_width;
    double y = y_index * tile_height;

    // Directly put the image on the window
    mlx_put_image_to_window(vars->mlx, vars->win, vars->tex[i].img, x, y);
}

void	draw_map(t_vars *vars)
{
	int x;
	int y;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == '1')
				draw_tile(vars, 0, x, y); // Wall
			else if (vars->map[y][x] == '0')
				draw_tile(vars, 1, x, y); // Blank
			else if (vars->map[y][x] == 'C')
				draw_tile(vars, 3, x, y); // Coin
			else if (vars->map[y][x] == 'E')
				draw_tile(vars, 4, x, y); // Exit
			x++;
		}
		y++;
	}
}

void draw_player(t_vars *vars)
{
	draw_tile(vars, 2, vars->pos->x, vars->pos->y);
}
