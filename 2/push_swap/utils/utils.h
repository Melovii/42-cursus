#ifndef UTILS
# define UTILS

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_list
{
	long int		content;
	int				flag;
	int				index;
	struct s_list	*next;
}				t_list;

// t_list	*ft_lstnew(void const *content);
t_list	*ft_lstnew(long int content);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);

long	ft_atoi(char *str);
int		ft_isdigit(int c);

void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);

#endif
