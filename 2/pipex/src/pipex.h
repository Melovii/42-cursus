#ifndef PIPEX_H
# define PIPEX_H

// ! don't forget about adding only necessary headers for BOTH files (ask co-workers for affirmation)

# include "../libft/libft.h"
# include <unistd.h> // fork(), access(), execve(), dup2(), close(), pipe()
# include <fcntl.h> // open(), file flags
# include <stdio.h> // perror()

// * apparently pid_t is SOMETIMES included in <unistd.h> but it's good practice to directly include it (for portability)
# include <sys/types.h> // for pid_t variable

// * apparently free() and exit() are also sometimes included in other headers, but it's important to DIRECTLY INCLUDE IT
# include <stdlib.h> // free(), exit()

// # include <errno.h> // for sterror return value // didn't use errno explicitly so no need

int		ft_open_file(char* file_name, int flow);
char	*ft_find_cmd(char* cmd, char** envp);
char	*ft_find_envp(char **envp);
void	ft_free_tab(char** tab);
void	error_handler(int n_error);

#endif