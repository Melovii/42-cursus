#include "pipex.h"

// ! pipe[0] = input (read)
// ! pipe[1] = output (write)
// * example usage: < infile grep a1 | wc -w > outfile

// TODO: check headers later on (move to header file perhaps)
// TODO: DECIDE HOW TO HANDLE SUCH ERRORS THAT WOULD TAKE A LOT OF LINES TO HANDLE BUT DON'T FALL INTO A CATEGORY IN ERROR_HANDLER() 
// TODO: if input file doesn't exist, set bytes to 0 on the output file
// * oh btw consider making the error_handler work with 2 parameters (with msg)

void	ft_execute(char* cmd, char** envp)
{
	char**	cmds;
	char*	path;

	cmds = ft_split(cmd, ' ');
	path = ft_find_cmd(cmd[0], envp); // ! confirm whether to use [0] or not
	
	// * Execute the command using execve(path, cmds, envp)
	// * If execve() fails:
	//     - Print error: "pipex: command not found: <cmd>"
	//     - Free cmds memory using ft_free_tab()
	//     - Exit the program with a failure status
}

void	child(char** argv, int* chan, char** envp)
{
	int	fd;

	// ! pipe[0] = input (read) = 0
	fd = ft_open_file(argv[1], 0);

	dup2(fd, 0);
	dup2(chan[1], 1);
	close(chan[0]);
	ft_execute(argv[2], envp); // execute cmd1
}

void	parent(char** argv, int* chan, char** envp)
{
	int	fd;

	// ! pipe[1] = output (write) = 1
	fd = ft_open_file(argv[4], 1);
	dup2(fd, 1);
	dup2(chan[0], 0);
	close(chan[1]);
	ft_execute(argv[3], envp); // execute cmd2
}

int main(int argc, char** argv, char** envp) // ? consider adding (char** envp) as an argument 
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

    // * Clean Up and Exit (consider making a function for this, or call in exec func)
    // Ensure all file descriptors are properly closed
    // Exit the program successfully (return 0)
}
