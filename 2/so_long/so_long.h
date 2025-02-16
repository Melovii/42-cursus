#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define RED_CROSS 33

# define SUCCESS 0
# define FAILURE 1

// * Stores image data for rendering
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpx;
	int		height;
	int		width;
	int		line_len;
	int		endian;
}			t_img;

// * Tracks keyboard inputs and movement direction
typedef struct s_key
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	dir;
}			t_key;

// * Stores the player's position
typedef struct s_pos
{
	int	x;
	int	y;
}			t_pos;

// * Game data
typedef struct s_vars
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_width;
	int		map_height;
	int		moves;
	int		coin;
	t_key	*key;
	t_pos	*pos;
	t_img	*img;
	t_img	tex[9];	// * textures
}			t_vars;

#endif
