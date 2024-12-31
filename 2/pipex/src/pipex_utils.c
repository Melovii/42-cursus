#include "pipex.h"

// TODO: remove error_handler function (not being used lol);

void	error_handler(int n_error)
{
	if (n_error == 1)
		ft_putstr_fd("Proper Usage: ./pipex infile \"cmd1\" \"cmd2\" outfile\n", 2);
	exit(0); 
}

int	ft_open_file(char* file_name, int flow)
{
	int	fd;

	if (flow)
		fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else
		fd = open(file_name, O_RDONLY, 0777);
	if (fd < 0)
	{
		ft_putstr_fd("bash: ", 2);
		perror(file_name);
		exit(0);
	}
	return (fd);
}

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

char	*ft_find_cmd(char* cmd, char** envp)
{
	char**	cmd_options;
	char**	path;
	char*	path_part;
	char*	exec;
	int		index;

	index = -1; // * don't use 0 lol
	path = ft_split(ft_find_envp(envp), ':');
	cmd_options = ft_split(cmd, ' ');
	while (path[++index])
	{
		path_part = ft_strjoin(path[index], "/"); // * basically from /usr/bin to /usr/bin
		exec = ft_strjoin(path_part, cmd_options[0]);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
		{
			ft_free_tab(cmd_options);
			return (exec); // ! why return exec if we're dead?
		}
		free(exec);
	}
	ft_free_tab(path);
	ft_free_tab(cmd_options);
	return (cmd);
}
