#include "../so_long.h"

static void	dfs(int r, int c, t_dfs_args *args)
{
	if (r < 0 || r >= args->vars->map_height || c < 0
		||c >= args->vars->map_width)
		return ;
	if (args->vars->map[r][c] == '1' || args->visited[r][c])
		return ;
	args->visited[r][c] = 1;
	if (args->vars->map[r][c] == 'C')
		(*args->collected)++;
	if (args->vars->map[r][c] == 'E')
		*args->exit_reached = 1;
	dfs(r + 1, c, args);
	dfs(r - 1, c, args);
	dfs(r, c + 1, args);
	dfs(r, c - 1, args);
}

static int	**allocate_visited(t_vars *vars)
{
	int	**visited;
	int	i;

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
	int			**visited;
	int			collected;
	int			exit_reached;
	int			i;
	t_dfs_args	args;

	visited = allocate_visited(vars);
	if (!visited)
		ft_exit(NULL, vars, FAILURE);
	collected = 0;
	exit_reached = 0;
	args.vars = vars;
	args.visited = visited;
	args.collected = &collected;
	args.exit_reached = &exit_reached;
	dfs(vars->pos->y, vars->pos->x, &args);
	i = 0;
	while (i < vars->map_height)
		free(visited[i++]);
	free(visited);
	if (collected != vars->coin)
		ft_exit(MSG_COINS, vars, FAILURE);
	if (!exit_reached)
		ft_exit(MSG_EXIT, vars, FAILURE);
	return (1);
}

int	check_is_file(char *argv, t_vars *vars)
{
	char	*ext;

	ext = ft_strrchr(argv, '.');
	if (!ext || ft_strncmp(ext, ".ber", ft_strlen(argv)) != 0)
		ft_exit("Error\n=> Foolish file extension\n", vars, FAILURE);
	return (1);
}

void	validate_elements(int *nbr, int r, t_vars *vars)
{
	if (!r)
	{
		if (nbr[0] < 1 || nbr[1] != 1 || nbr[2] != 1)
			ft_exitc(1, vars, FAILURE);
	}
}
