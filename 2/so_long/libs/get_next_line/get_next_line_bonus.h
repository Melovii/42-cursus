#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(char *str);
int		ft_found_newline(char *buffer);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_extract_line(char *buffer);
char	*ft_trim_buffer(char *buffer);
char	*get_next_line(int fd);

#endif
