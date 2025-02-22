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

# define TITLE "Guided by Grace"

# define SCALE_FACTOR 2

# define TEX_WALL "./textures/border.xpm"
# define TEX_BLANK "./textures/mars.xpm"
# define TEX_PLAYER "./textures/tarnished.xpm"
# define TEX_COIN "./textures/rune.xpm"
# define TEX_EXIT "./textures/door.xpm"

# define MSG_COINS "Error\n=> Lay these foolish ambitions to rest, no runes.\n"
# define MSG_EXIT "Error\n=> Tarnished… the grace shine not upon this path.\n"
# define MSG_WIN "Thou hast triumphed, Tarnished. Thou art a true victor.\n"

// * Holds info related to map file reading and parsing
typedef struct s_parse
{
	int		read;
	char	*line;
	int		total_lines;
	int		line_len;
	int		prev_len;
	int		fd;
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
	t_img	tex[5];
}			t_vars;

// * Structure for DFS algorithm
typedef struct s_dfs_args
{
	t_vars	*vars;
	int		**visited;
	int		*collected;
	int		*exit_reached;
}			t_dfs_args;

// * Function prototypes:

int			ft_exit(char *msg, t_vars *vars, int ret);
int			ft_exitc(int set, t_vars *vars, int ret);

t_parse		valid_map_file(char *argv, t_vars *vars);
void		parse_map(char *argv, t_vars *vars);
int			check_is_file(char *argv, t_vars *vars);
void		validate_elements(int *nbr, int r, t_vars *vars);
int			check_path_to_coin(t_vars *vars);

t_key		*init_keys(void);
int			key_press(int keycode, t_vars *vars);
int			key_release(int keycode, t_vars *vars);
int			key_event(t_vars *vars);

void		tex_all(t_vars *vars);
int			gameloop(t_vars *vars);

void		move_player(t_vars *vars);
void		draw_map(t_vars *vars);
void		draw_player(t_vars *vars);

#endif
