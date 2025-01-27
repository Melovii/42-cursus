#include "push_swap.h"

// * Initializes the stack with the provided arguments
static t_list	*ft_init_stacks(char **ag, int ac)
{
	t_list	*res;  // Pointer to hold the resulting stack
	int		i;      // Index for iterating through arguments

	i = 1;
	// If there is only one argument (argc == 2), start at index 0
	if (ac == 2)
		i = 0;
	res = NULL;
	// Loop through the arguments to build the stack
	while (ag[i])
	{
		// Process the argument and add it to the stack
		// If it fails, return NULL
		if (!process_argument(ag[i], &res))
			return (NULL);
		i++;
	}
	return (res);
}

// * Parses and prepares arguments for stack initialization
static char	**parse_arguments(int argc, char **argv)
{
	// If there's only one argument (argc == 2), split it by spaces
	// Otherwise, return the original arguments
	if (argc == 2)
		return (ft_split(argv[1], ' '));
	return (argv);
}

// * Allocates and initializes the t_swap structure
static t_swap	*initialize_tab(void)
{
	t_swap	*tab;

	// Allocate memory for the t_swap structure
	tab = malloc(sizeof(t_swap));
	if (!tab)
	{
		// If allocation fails, print an error and return NULL
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	// Initialize the stacks as NULL
	tab->stack_a = NULL;
	tab->stack_b = NULL;
	return (tab);
}

// * Sets up the stacks and their sizes in the t_swap structure
static int	setup_stacks(t_swap *tab, char **args, int argc)
{
	// Initialize stack A with the given arguments
	tab->stack_a = ft_init_stacks(args, argc);
	// If the arguments were split (argc == 2), free them
	if (argc == 2)
		free_args(args); // Free args if allocated by ft_split
	// If stack A was not initialized correctly, free the tab and return failure
	if (!tab->stack_a)
	{
		free_tab(tab);
		return (0);
	}
	// Initialize stack B as NULL (it starts empty)
	tab->stack_b = NULL;
	// Set the size of stack A and B
	tab->asize = ft_lstsize(tab->stack_a);
	tab->bsize = ft_lstsize(tab->stack_b);
	// Add index to stack A's elements (presumably for sorting)
	add_index(tab->stack_a);
	return (1); // Return success
}

int	main(int argc, char **argv)
{
	t_swap	*tab;   // Pointer to hold the t_swap structure
	char	**args;  // Parsed arguments

	// If no arguments are provided, just return (no action)
	if (argc == 1)
		return (0);
	// Initialize the t_swap structure
	tab = initialize_tab();
	if (!tab)
		return (-1); // If initialization failed, return error
	// Parse the arguments for stack initialization
	args = parse_arguments(argc, argv);
	if (!args)
	{
		// If parsing failed, free the tab and return error
		free_tab(tab);
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	// Set up the stacks using the parsed arguments
	if (!setup_stacks(tab, args, argc))
		return (-1); // If stack setup failed, return error
	// Call the sorting function
	sort_call(tab);
	// Free allocated memory for the t_swap structure
	free_tab(tab);
	return (0); // Successful execution
}
