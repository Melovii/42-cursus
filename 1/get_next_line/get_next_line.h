#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1042
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

// * FUNCTION PROTOTYPES
char	*fill_line_buffer(int fd, char *left_c, char *buffer);
char	*set_line(char *line_buffer);
char	*get_next_line(int fd);

// * UTILITY FUNCTIONS
// ! UNUSED: size_t	ft_strlen(const char *str);
// ! UNUSED: char	*ft_strchr(const char *str, int c);
// ! UNUSED: char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
