#ifndef PUSH_SWAP
# define PUSH_SWAP

// # include "../libft/libft.h"
# include "../utils/utils.h"
# include <limits.h>

// TODO: consider updating implementation to work with libft's t_list struct
// ! BTW... do I need to make all functions start with ft?
// ! DO NOT forget to apply new norm rules
// TODO: consider changing swap struct name to stack

// typedef struct	s_list
// {
// 	long int		content;
// 	int				flag;
// 	int				index;
// 	struct s_list	*next;
// }				t_list;

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


void	check_sort(t_swap *tab);
void	add_index(t_list *lst);

t_list	*find_min_lst(t_list **stack);
t_list	*find_max_lst(t_list **stack);

int		is_sorted(t_list **stack);
int		is_rev_sorted(t_swap *tab);
int		lst_valid(t_list **stack, int count);
void	ft_quick_sort(t_list **stack1, t_list **stack2, int count);

void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);

void	sa(t_list** stack_a);
void	sb(t_list** stack_b);
void	ss(t_list** stack_a, t_list** stack_b);

void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);

void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);


#endif