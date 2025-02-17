#include "../so_long.h"

int	check_is_file(char *argv, t_vars *vars)
{
	int	i;

	i = ft_strlen(argv);
	while (argv[i] != '.')
	{
		if (i == 0)
			ft_exit("Error\nInvalid file\n", vars, FAILURE);
		i--;
	}
	i++;
	if (ft_strncmp((argv + i), "ber", ft_strlen(argv)) != 0) // ? CHECK IF STRLEN(ARGV[I]) PART WORKS OR NOT
		ft_exit("Error\nInvalid file extension\n", vars, FAILURE);
	return (1);
}

void	validate_elements(int *nbr, int r, t_vars *vars)
{
	int	i;

	i = 0;
	if (!r)
	{
		while (i < 3)
		{
			if (nbr[i++] < 1 || nbr[2] > 1)
				ft_exitc(4, vars, FAILURE);
		}
	}
}
