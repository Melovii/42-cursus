#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "../libft/libft.h"
# include <limits.h>

typedef struct	s_push
{
	int	next;
	int	mid;
	int	max;
	int	flag;
}				t_push;

typedef struct	s_swap
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		a_size;
	int		b_size;
}				t_swap;

// ! include function prototypes here

#endif