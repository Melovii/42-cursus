#include "../so_long.h"

static void	dfs(t_vars *vars, int r, int c, int **visited, int *collected)
{
	if (r < 0 || r >= vars->map_height || c < 0 || c >= vars->map_width)
		return;
	if (vars->map[r][c] == '1' || visited[r][c])
		return;
	visited[r][c] = 1;
	if (vars->map[r][c] == 'C')
		(*collected)++;
	dfs(vars, r + 1, c, visited, collected);
	dfs(vars, r - 1, c, visited, collected);
	dfs(vars, r, c + 1, visited, collected);
	dfs(vars, r, c - 1, visited, collected);
}

static int	**allocate_visited(t_vars *vars)
{
	int **visited;
	int i;
	i = 0;
	visited = ft_calloc(sizeof(int *), vars->map_height);
	if (!visited)
		ft_exit(NULL, vars, FAILURE);
	while (i < vars->map_height)
	{
		visited[i] = ft_calloc(sizeof(int), vars->map_width);
		if (!visited[i])
			ft_exit(NULL, vars, FAILURE);
		i++;
	}
	return (visited);
}

int	check_path_to_coin(t_vars *vars)
{
	int	**visited;
	int	collected;
	int	i;

	collected = 0;
	visited = allocate_visited(vars);
	dfs(vars, vars->pos->y, vars->pos->x, visited, &collected);
	i = 0;
	while (i < vars->map_height)
		free(visited[i++]);
	free(visited);
	return (collected == vars->coin);
}

int	check_is_file(char *argv, t_vars *vars)
{
	char *ext;

	ext = ft_strrchr(argv, '.');
	if (!ext || ft_strncmp(ext, ".ber", ft_strlen(argv)) != 0)
		ft_exit("Error\nInvalid file extension\n", vars, FAILURE);
	return (1);
}

void	validate_elements(int *nbr, int r, t_vars *vars)
{
	if (!r)
	{
		if (nbr[0] < 1 || nbr[1] != 1 || nbr[2] != 1)
			ft_exitc(4, vars, FAILURE);
	}
}
