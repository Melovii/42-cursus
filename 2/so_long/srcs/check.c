#include "../so_long.h"

// ! why are my functions static ?????????

static int	is_border_line(char *line, int len)
{
	int	i;

	(void)len;
	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	map_has_walls(char *line, int is_border, int len, t_vars *vars)
{
	if (is_border)
	{
		if (!is_border_line(line, len))
			ft_exitc(1, vars, FAILURE);
	}
	else
	{
		if (line[0] != '1' || line[len - 1] != '1')
			ft_exitc(1, vars, FAILURE);
	}
	return (1);
}

// * Checks if map line contains only valid characters
static int	map_is_valid(char *line, t_vars *vars)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'P'
			&& line[i] != 'C' && line[i] != 'E')
			ft_exitc(2, vars, FAILURE);
		i++;
	}
	return (1);
}

// * Checks if there exists: 1 exit, 1 starting position, and at least 1 coin
static int	count_map_elements(char *line, int r, t_vars *vars)
{
	static int	nbr[3] = {0}; // C, P, E counts
	int			i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'C')
			nbr[0]++;
		else if (line[i] == 'P')
			nbr[1]++;
		else if (line[i] == 'E')
			nbr[2]++;
		i++;
	}
	validate_elements(nbr, r, vars);
	return (1);
}

// * Checks if the map is rectangular (All lines being of equal lengths) and more
void	validate_map_lines(t_parse *check, t_vars *vars)
{
	while (check->read > 0)
	{
		check->prev_len = check->line_len;
		check->read = get_next_line(check->fd, &check->line);
		check->line_len = ft_strlen(check->line);
		if (check->prev_len != -1 && check->prev_len != check->line_len)
			ft_exitc(6, vars, FAILURE);
		count_map_elements(check->line, check->read, vars);
		map_is_valid(check->line, vars);
		if (check->total_lines++ == 0 || check->read == 0)
			map_has_walls(check->line, 1, check->line_len, vars);
		else
			map_has_walls(check->line, 0, check->line_len, vars);
		free(check->line);
	}
}

// * Checks if the map file exists
t_parse	valid_map_file(char *argv, t_vars *vars)
{
	t_parse	check;

	ft_bzero(&check, sizeof(t_parse)); // ! lmao why ft_bzero..?
	vars->fail = 0;
	check.line_len = -1;
	check.read = 1;
	check.fd = open(argv, O_RDWR, 777);
	if (check.fd < 0)
		ft_exitc(5, vars, FAILURE);
	validate_map_lines(&check, vars);
	close(check.fd);
	ft_exitc(0, vars, FAILURE);
	return (check);
}
