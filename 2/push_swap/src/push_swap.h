#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "../libft/libft.h"
# include <limits.h>

// TODO: consider updating implementation to work with libft's t_list struct

typedef struct	s_liist
{
	long int		content;
	int				flag;
	int				index;
	struct s_liist	*next;
}				t_liist;

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

void	pa(t_liist **stack_a, t_liist **stack_b);
void	pb(t_liist **stack_a, t_liist **stack_b);

void	sa(t_liist** stack_a);
void	sb(t_liist** stack_b);
void	ss(t_liist** stack_a, t_liist** stack_b);

void	ra(t_liist **stack_a);
void	rb(t_liist **stack_b);
void	rr(t_liist **stack_a, t_liist **stack_b);

void	rra(t_liist *stack_a);
void	rrb(t_liist *stack_b);
void	rrr(t_liist *stack_a, t_liist *stack_b);


#endif