#include "../so_long.h"

void	extract_map_data(t_vars *vars, t_parse map_info)
{
	int	row;
	int	col;
	
	row = 0;
	vars->coin = 0;
	while (vars->map[row][col])
	{
		col = 0;
		while (vars->map[row][col])
		{
			if (vars->map[row][col] == 'C')
				vars->coin++;
			if (vars->map[row][col] == 'P')
			{
				vars->pos->x = col;
				vars->pos->y = row;
				vars->map[row][col] = '0';
			}
			col++;
		}
		row++;
	}
	vars->map_width = map_info.line_len;		// Lenght of the current line
	vars->map_height = map_info.total_lines;	// Total number of lines (rows) in the map
}

void	parse_map()
{
	t_parse	map_info;
	int		i;

	i = 0;
	// TODO: map_info files here
	// ? File exists ?
	// ? Map is rectangular ? (all lines should be the same length)
	// ? Something is in the map ? (other than 01CPE)
	// ? Map is enclosed with walls ? (first and lanst lines and columns must be 1)
	// ? Only one exit exists ?
	// ? Only one start position ?
	// ? At least one coin ?
	// ! ADVANCED CHECK: all coins are collectible??? !
}