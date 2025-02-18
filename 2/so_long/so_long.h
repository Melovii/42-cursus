#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libs/libft/libft.h"
# include "./libs/minilibx-linux/mlx.h"

# define KEY_ESC 65307
# define KEY_EXIT 33
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define SUCCESS 0
# define FAILURE 1

# define TITLE "mac-pan (pac-man lmao)"

# define TEX_WALL "./textures/border.xpm"
# define TEX_BLANK "./textures/space.xpm"
# define TEX_PLAYER "./textures/pacman.xpm"
# define TEX_COIN "./textures/coin.xpm"
# define TEX_EXIT "./textures/strawberry.xpm"

// * Holds info related to map file reading and parsing
typedef struct s_parse
{
	int		read;			// Number of bytes read from the map file or whether there are more lines to
	char	*line;			// Holds a single line from the map file being read
	int		total_lines;	// Total number of lines processed (height of the map)
	int		line_len;		// Length of the current line being read (max width of the map)
	int		prev_len;		// Length of the previous line (used for checking consistency of map width)
	int		fd;				// File Descriptor for the map file, used to read the file
}			t_parse;

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
	int		fail;
	int		moves;
	int		coin;
	t_key	*key;
	t_pos	*pos;
	t_img	*img;
	t_img	tex[5];	// textures
}			t_vars;

// * Function prototypes:

t_parse		valid_map_file(char *argv, t_vars *vars);
int			ft_exit(char *msg, t_vars *vars, int ret);
int			ft_exitc(int set, t_vars *vars, int ret);
void		parse_map(char *argv, t_vars *vars);
int			check_is_file(char *argv, t_vars *vars);
void		validate_elements(int *nbr, int r, t_vars *vars);
t_key   	*init_keys(void);
int			key_press(int keycode, t_vars *vars);
int			key_release(int keycode, t_vars *vars);
int			key_event(t_vars *vars);
void		tex_all(t_vars *vars);
int			gameloop(t_vars *vars);
void		move_player(t_vars *vars);
void 		draw_map(t_vars *vars);
void 		draw_player(t_vars *vars);

// ! and other function prototypes lol

#endif
