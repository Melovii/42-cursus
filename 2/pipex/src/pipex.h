#ifndef PIPEX_H
# define PIPEX_H

// TODO: get rid of unnecessary headers and consider changing structure
// ! don't forget about adding only necessary headers for BOTH files (ask co-workers for affirmation)

# include "../libft/libft.h"
# include <unistd.h> // pipe, write, read maybe
# include <stdlib.h> // malloc // didn't use malloc lol
# include <fcntl.h> // open
# include <errno.h> // for perror()
# include <stdio.h> // for perror() too lol

// Step 1: Include necessary function prototypes
// For example:
// - find_command_path() to search for the full path of a command
// - Any utility functions for string manipulation (ft_split, ft_strjoin, etc.)

int		ft_open_file(char* file_name, int flow);
char	*ft_find_cmd(char* cmd, char** envp);
char	*ft_find_envp(char **envp);
void	ft_free_tab(char** tab);
void	error_handler(int n_error);

#endif