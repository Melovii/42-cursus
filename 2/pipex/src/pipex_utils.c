#include "pipex.h"

// Handle different error cases for the program.
// If n_error == 1, print an error message about incorrect command usage and exit.
void	error_handler(int n_error)
{
	if (n_error == 1)
		ft_putstr_fd("./pipex infile cmd | cmd outfile\n", 2);
	exit(0); 
}

// Open a file with the given file name and mode (flow). Handle errors appropriately.
int	ft_open_file(char* file_name, int flow)
{
	int	fd;

	if (flow)
		fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else
		fd = open(file_name, O_RDONLY, 0777);

	if (fd < 0)
		exit(0);

	return (fd);
}

// TODO: Implement ft_free_tab function
// This function frees memory allocated for a table (array) of strings.

void	ft_free_tab(char** tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

// TODO: Implement ft_get_envp function
// This function retrieves a specific environment variable's value from the environment variables array.
char	*ft_find_envp(char **envp)
{
	int		i;
	char*	envp_path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			envp_path = envp[i] + 5;
			break ;
		}
		i++;
	}

	if (!envp_path)
		exit(1);

	return (envp_path);
}
// TODO: Implement ft_find_cmd function
// This function will search for the full path of the given command in the directories listed in the PATH envpironment variable.
char	*ft_find_cmd(char* cmd, char** envp)
{
	char**	cmd_options;
	char**	path;
	char*	path_part;
	char*	exec;
	int		index;

	index = -1; // don't use 0 lol
	path = ft_split(ft_find_envp(envp), ':');
	cmd_options = ft_split(cmd, ' ');
	while (path[++index])
	{
		path_part = ft_strjoin(path[index], "/"); // basically from /usr/bin to /usr/bin
		exec = ft_strjoin(path_part, cmd_options[0]);
		// ? ? ? ? ? ? ? ? ?
		free(path_part); // ! WHY FREE?
		if (access(exec, F_OK | X_OK) == 0)
		{
			ft_free_tab(cmd_options);
			return (exec); // ? why return exec if we're dead?
		}
		free(exec);
	}
	ft_free_tab(path);
	// ? ? ? ? ? ? ? ? ? ? ? ? ? ?
	ft_free_tab(cmd_options); // ! WHY FREE?
	return (cmd);
}
