#include "pipex.h"

// Step 1: Implement find_command_path function
// TODO: This function will search for the full path of the given command in the directories listed in the PATH environment variable.
// TODO: Use getenv("PATH") to retrieve the PATH variable.
// TODO: Split the PATH variable into directories (using ft_split or any string splitting method).
// TODO: Iterate over each directory and try to find the command using access() with X_OK flag.
// TODO: If the command is found, return the full path of the command.
// TODO: If no valid path is found, return NULL.
char	*find_command_path(char *command)
{
	// Function implementation will go here
}

// Step 2: Implement error_handler function
// TODO: Handle different error cases for the program.
// TODO: If n_error == 1, print an error message about incorrect command usage and exit.
void	error_handler(int n_error)
{
	if (n_error == 1)
		ft_putstr_fd("./pipex infile cmd | cmd outfile\n", 2);
	exit(0); 
}

// Step 3: Implement ft_open_file function
// TODO: Open a file with the given file name and mode (flow). Handle errors appropriately.
int	ft_open_file(char *file_name, int flow)
{
	int	fd;

	if (flow)
	{
		fd = open(file_name, O_WRONLY);
	}
	else
	{
		fd = open(file_name, O_RDONLY);
	}
	// ! handle error, use a different way
	if (fd < 0)
	{
		perror("Can not open file / File not found in directory");
		error_handler(1); // ? should I use error_handler(0) or exit(1) or exit(0) instead?
	}
	return (fd);
}

// Step 4: Implement ft_free_tab function
// TODO: Free memory used by a table (array) of strings.
void	ft_free_tab(char **tab)
{
	// Function implementation will go here
}

// Step 5: Implement ft_get_env function
// TODO: Get environment variables and return the relevant information.
char	*ft_find_env(char *name, char **env)
{
	// Function implementation will go here
}

// Step 6: Implement ft_get_path function
// TODO: Retrieve and return the PATH environment variable from the environment.
char	*ft_find_cmd(char *cmd, char **env)
{
	// Function implementation will go here
}
