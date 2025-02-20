#include "../so_long.h"

int	check_is_file(char *argv, t_vars *vars)
{
	char	*ext;

	ext = ft_strrchr(argv, '.');
	if (!ext || ft_strncmp(ext, ".ber", strlen(argv)) != 0)
		ft_exit("Error\nInvalid file extension\n", vars, FAILURE);
	return (1);
}

void	validate_elements(int *nbr, int r, t_vars *vars)
{
	if (!r)
	{
		if (nbr[0] < 1) // At least one collectible
			ft_exitc(4, vars, FAILURE);
		if (nbr[1] != 1) // Exactly one player
			ft_exitc(4, vars, FAILURE);
		if (nbr[2] != 1) // Exactly one exit
			ft_exitc(4, vars, FAILURE);
	}
}
