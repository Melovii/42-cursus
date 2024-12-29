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
		fd = open(file_name, O_WRONLY);
	else
		fd = open(file_name, O_RDONLY);

	// ! handle error, use a different way
	if (fd < 0)
	{
		perror("Can not open file / File not found in directory");
		error_handler(1); // ? should I use error_handler(0) or exit(1) or exit(0) instead?
	}
	return (fd);
}

// TODO: Implement ft_free_tab function
// This function frees memory allocated for a table (array) of strings.

void	ft_free_tab(char** tab)
{
	// * Iterate through the array and free each string.
	// * Free the array itself after all strings have been freed.

	// Check if `tab` is not NULL.
	// Iterate through the array:
	//  - Use a loop to access each element (tab[i]).
	//  - Call `free()` on each element to release its memory.
	// After freeing all strings, free the array itself (the `tab` pointer).
	// Ensure the pointer `tab` is not dereferenced after freeing.
}

// TODO: Implement ft_get_envp function
// This function retrieves a specific environment variable's value from the environment variables array.
char	*ft_find_envp(char* name, char **envp)
{
	// * Iterate through the `envp` array to find the variable matching `name`.
	// * Return the value of the variable if found (the part after the '=' character).
	// * If the variable is not found, return NULL.

	// Check if `name` and `envp` are not NULL.
	// Iterate through the `envp` array:
	//  - Use `strncmp()` to compare the beginning of each string in `envp` with `name`.
	//  - Check if the string contains `name=` (variable name followed by '='). 
	//    - For example, "PATH=/usr/bin" matches "PATH".
	// If a match is found:
	//  - Use `strchr()` or pointer arithmetic to locate the '=' character in the string.
	//  - Return a pointer to the substring after '=' (the value of the environment variable).
	// If no match is found, return NULL.
}
// TODO: Implement ft_find_cmd function
// This function will search for the full path of the given command in the directories listed in the PATH envpironment variable.
char	*ft_find_cmd(char* cmd, char** envp)
{
	// Use getenvp("PATH") to retrieve the PATH variable.
	// Split the PATH variable into directories (using ft_split or any string splitting method).
	// Iterate over each directory and try to find the command using access() with X_OK flag.
	// If the command is found, return the full path of the command.
	// If no valid path is found, return NULL.
	// Retrieve and return the PATH envpironment variable from the envpironment.
}
