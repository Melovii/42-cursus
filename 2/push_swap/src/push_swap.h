#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../utils/utils.h"
# include <limits.h>

// ! BTW... do I need to make all functions start with ft?
// ! DO NOT forget to apply new norm rules
// TODO: consider changing swap struct name to stack
// ! do I make functions static? uhhh ._.

typedef struct s_push
{
	int	next;
	int	max;
	int	mid;
	int	flag;
}	t_push;

typedef struct s_swap
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		asize;
	int		bsize;
}		t_swap;


int		is_sorted(t_list **stack1);
int		is_rev_sorted(t_swap *tab);
int		lst_valid(t_list **stack1, int count);

t_list	*find_min_lst(t_list **stack);
t_list	*find_max_lst(t_list **stack);

void	quick_sort(t_list **stack1, t_list **stack2, int count);
void	sort_call(t_swap *tab);
void	add_index(t_list *lst);

void	pa(t_list **stack1, t_list **stack2);
void	pb(t_list **stack1, t_list **stack2);

void	ra(t_list **stack1);
void	rb(t_list **stack2);
void	rr(t_list **stack1, t_list **stack2);

void	rrb(t_list **stack2);
void	rra(t_list **stack1);

void	sa(t_list **stack1);
void	sb(t_list **stack2);
void	ss(t_list **stack1, t_list **stack2);

#endif
