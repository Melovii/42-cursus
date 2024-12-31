#include "pipex.h"

// ! pipe[0] = input (read)
// ! pipe[1] = output (write)
// * example usage: < infile grep a1 | wc -w > outfile
// * example usage: ./pipex infile "grep a1" "wc -w" outfile

// TODO: if input file doesn't exist, set bytes to 0 on the output file // uhh what lol is this for cat?

static void	ft_execute(char* cmd, char** envp)
{
	char**	cmds;
	char*	path;

	cmds = ft_split(cmd, ' ');
	path = ft_find_cmd(cmds[0], envp);
	
	if(execve(path, cmds, envp) == -1)
	{
		ft_putstr_fd(cmds[0], 2);
		ft_putendl_fd(": command not found ", 2);
		ft_free_tab(cmds);
		exit(0);
	}
}

static void	child(char** argv, int* chan, char** envp) // * reading end
{
	int	fd;

	fd = ft_open_file(argv[1], 0);
	dup2(fd, 0);
	dup2(chan[1], 1);
	close(chan[0]);
	ft_execute(argv[2], envp); // * execute cmd1
}

static void	parent(char** argv, int* chan, char** envp) // * writing end
{
	int	fd;

	fd = ft_open_file(argv[4], 1);
	dup2(fd, 1);
	dup2(chan[0], 0);
	close(chan[1]);
	ft_execute(argv[3], envp); // * execute cmd2
}

int main(int argc, char** argv, char** envp)
{
	int		chan[2];
	pid_t	pid;

	if (argc != 5)
	{
		ft_putstr_fd("Proper Usage: ./pipex infile \"cmd1\" \"cmd2\" outfile\n", 2);
		exit(0);
		// error_handler(1);
	}
	if (pipe(chan) < 0)
	{
		exit(-1);
	}
	pid = fork();
	if (pid < 0)
	{
		exit(-1);
	}
	if (pid == 0)
	{
		child(argv, chan, envp);
	}
	parent(argv, chan, envp);
	return (0);
}
