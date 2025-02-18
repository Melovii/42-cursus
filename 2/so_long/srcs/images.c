#include "../so_long.h"

// * Puts a pixel of a given color at (x, y) in the image buffer
void pixel_put_color(t_vars *vars, int x, int y, unsigned int color)
{
	char	*dst;
	
	dst = vars->img->addr + (y * vars->img->line_len + x * vars->img->bpx / 8);
	*(unsigned int *)dst = color;
	// * I still do not understand this shit.
	// TODO: Convert pixel coordinates to the correct memory offset
	// TODO: Get the memory address of the pixel at (x, y)
	// TODO: Set the pixel color at the calculated address
}

// * Draws a single tile (or sprite) at the given map coordinates (segfault...)
void draw_tile(t_vars *vars, int i, int x_index, int y_index)
{
	const double	tile_width = ((double)(100 * vars->map_width)) / vars->map_width;
	const double	tile_height = ((double)(100 * vars->map_height)) / vars->map_height;
	char			*addr;
	double			x;
	double			y;

	y = 0.0;
	while (y < tile_height)
	{
		x = 0.0;
		while (x < tile_width)
		{
			addr = vars->tex[i].addr;
			addr += (size_t)((y / tile_height) * vars->tex[i].height) * vars->tex[i].line_len; // if you wanna go to the next row, you gotta shift the whole line lol
			addr += (size_t)((x / tile_width) * vars->tex[i].width) * 4; // shit is 4 bytes
			pixel_put_color(vars, x + (x_index * tile_width), y + (y_index * tile_height), *(unsigned int *)addr);
			x++;
		}
		y++;
	}
	// * I still do not understand this shit.
	// TODO: Calculate the size of one tile in pixels based on map size
	// TODO: Loop over each pixel in the tile
	// TODO: Get the texture color from the corresponding texture
	// TODO: Draw the pixel using pixel_put_color
}

// * Renders the entire map by drawing each tile in its correct position
void draw_map(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'C')
				draw_tile(vars, 2, x, y);
			else if (vars->map[y][x] == 'E')
				draw_tile(vars, 3, x, y);
			else if (vars->map[y][x] == '0')
				draw_tile(vars, 4, x, y);
			else if (vars->map[y][x] == '1')
				draw_tile(vars, 1, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	// TODO: Loop through each row in the map
	// TODO: Loop through each column in the row
	// TODO: Check the type of tile ('C', 'E', '1', etc.)
	// TODO: Call draw_one_pixe with the correct texture index
	// TODO: Push the image to the window
}

// * Draws the player sprite at its current position
void draw_player(t_vars *vars)
{
	draw_tile(vars, vars->key->dir, vars->pos->x, vars->pos->y); // how does dir even work atp lmfao
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	// TODO: Call draw_one_pixe with the player’s current position and texture
	// TODO: Push the updated image to the window
}


// ! this whole file: WHAT. THE. FUCK.