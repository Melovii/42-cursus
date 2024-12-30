#include "pipex.h"

// ! pipe[0] = input (read)
// ! pipe[1] = output (write)
// * example usage: < infile grep a1 | wc -w > outfile
// * example usage: ./pipex infile "grep a1" "wc -w" outfile

// TODO: DECIDE HOW TO HANDLE SUCH ERRORS THAT WOULD TAKE A LOT OF LINES TO HANDLE BUT DON'T FALL INTO A CATEGORY IN ERROR_HANDLER()
// TODO: if input file doesn't exist, set bytes to 0 on the output file
// TODO: add messages based on the subject.pdf for when it fails
// TODO: check all the frees that I've used.. are they even necessary?
// TODO: test the hell out of the program lol (oh and uhh.. wtf about leaks? lol)

// * oh btw consider making the error_handler work with 2 parameters (with msg)

static void	ft_execute(char* cmd, char** envp)
{
	char**	cmds;
	char*	path;

	cmds = ft_split(cmd, ' ');
	path = ft_find_cmd(cmds[0], envp);
	
	if(execve(path, cmds, envp) == -1)
	{
		// ? can not understand this check...
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmds[0], 2);
		ft_free_tab(cmds);
		exit(0);
	}
}

static void	child(char** argv, int* chan, char** envp)
{
	int	fd;

	// ! pipe[0] = input (read) = 0
	fd = ft_open_file(argv[1], 0);

	dup2(fd, 0);
	dup2(chan[1], 1);
	close(chan[0]);
	ft_execute(argv[2], envp); // execute cmd1
}

static void	parent(char** argv, int* chan, char** envp)
{
	int	fd;

	// ! pipe[1] = output (write) = 1
	fd = ft_open_file(argv[4], 1);
	dup2(fd, 1);
	dup2(chan[0], 0);
	close(chan[1]);
	ft_execute(argv[3], envp); // execute cmd2
}

int main(int argc, char** argv, char** envp)
{
	int		chan[2];
	pid_t	pid;

	if (argc != 5)
		error_handler(1);

	if (pipe(chan) < 0)
		exit(-1);

	pid = fork();
	if (pid < 0)
		exit(-1);

	if (pid == 0)
		child(argv, chan, envp);

	parent(argv, chan, envp);

	return (0);
}
