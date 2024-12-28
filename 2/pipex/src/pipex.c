// Check the existence of infile and outfile
	// be sure to understand what > does when the file does not exist
	// - for cat -> sets bytes as 0 (supposedly for most things.. cause it's writing after all?)

// Create the necessary pipe (or pipes)
	// pipe() if I don't make bonus
// Create a child process for each command
// Wait for all the processes to end before writing to the outfile

// ! pipe[0] = input (read)
// ! pipe[1] = output (write)

// * example usage: < infile grep a1 | wc -w > outfile

#include "pipex.h"
#include <errno.h> // * for perror()
#include <stdio.h> // * for perror() too lol
// TODO: check headers later on (move to header file perhaps)

int main(int argc, char **argv) // ? consider adding (char **envp) as an argument 
{
	int	chan[2];
	int	inputFD;
	int	outputFD;
    // Step 1: Argument Parsing
    // Check if the number of arguments is correct (argc should be 5)
    // If not, print an error message and return an error code (1)
	if (argc != 4)
		error_handler();

    // Step 2: File Handling
    // Open the input file (file1) for reading using open()
    // If file cannot be opened, print an error message and exit the program
	inputFD = ft_open_file("infile", 0);
	outputFD = ft_open_file("outfile", 1);
    
    // Step 3: Create Pipe(s)
    // Create a pipe using the pipe() system call to link the commands together
    // If pipe creation fails, print an error message and close any opened files
	
	// ! ! ! !
	// TODO: DECIDE HOW TO HANDLE SUCH ERRORS, ERRORS THAT WOULD TAKE A LOT OF LINES TO HANDLE BUT DON'T FALL INTO A CATEGORY IN ERROR_HANDLER() 
	if (pipe(chan) < 0)
	{
		perror("pipe");
		exit(1);
	}


    // Step 4: First Command Execution (cmd1)
    // Fork a child process using fork()
    // In the child process:
    //     - Redirect stdin to the input file using dup2()
    //     - Redirect stdout to the write end of the pipe using dup2()
    //     - Close any unused file descriptors (input file and pipe write end)
    //     - Execute cmd1 using execve()
    //     - If execve() fails, print an error message and exit

    // Step 5: Second Command Execution (cmd2)
    // Fork another child process using fork()
    // In the second child process:
    //     - Redirect stdin to the read end of the pipe using dup2()
    //     - Redirect stdout to the output file using dup2()
    //     - Close any unused file descriptors (pipe read end and output file)
    //     - Execute cmd2 using execve()
    //     - If execve() fails, print an error message and exit

    // Step 6: Parent Process
    // Close the file descriptors (input file, output file, and pipe ends) in the parent process
    // Wait for both child processes to finish using wait() or waitpid()

    // Step 7: Clean Up and Exit
    // Ensure all file descriptors are properly closed
    // Exit the program successfully (return 0)
}
