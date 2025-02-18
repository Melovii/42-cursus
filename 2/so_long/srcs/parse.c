#include "../so_long.h"

void	extract_map_data(t_vars *vars, t_parse map_info)
{
	int	row;
	int	col;
	
	row = 0;
	vars->coin = 0;
	while (vars->map[row])
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

void	parse_map(char *argv, t_vars *vars)
{
	t_parse	map_info;
	int		i;

	i = 0;
	check_is_file(argv, vars);
	map_info = valid_map_file(argv, vars);
	vars->map = ft_calloc(sizeof(char *), (map_info.total_lines + 1));
	if (!vars->map)
		ft_exit(NULL, vars, FAILURE);
	map_info.fd = open(argv, O_RDWR, 777);
	map_info.read = 1;
	while (map_info.read)
	{
		map_info.read = get_next_line(map_info.fd, &map_info.line);
		vars->map[i++] = ft_strdup(map_info.line);
		free(map_info.line);
	}
	close (map_info.fd);
	extract_map_data(vars, map_info);
	// ! ADVANCED CHECK: all coins are collectible??? !
}
