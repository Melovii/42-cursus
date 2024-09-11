#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

/* -=-=-=-=- 	NUMBERS		-=-=-=-=-=- */
char	*ft_itoa(int nbr);
int		ft_atoi(const char *str);
int		ft_numlen(long int nbr);
int		ft_abs(long int nbr);

/* -=-=-=-=- 	CHARS		-=-=-=-=-=- */
int		ft_isprint(int c);
int		ft_isascii(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isspace(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	ft_putchar(char c);

/* -=-=-=-=-	STRINGS		=-=-=-=-=-=- */
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strcat(char *dest, char *src);
char	*ft_strncat(char *dest, char *src, int nb);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strncpy(char *dest, const char *src, unsigned int n);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strstr(char *str, char *to_find);
void	ft_putstr(char const *s);
void	ft_striter(char *s, void(*f)(char *));
void	ft_striteri(char *s, void(*f)(unsigned int, char *));
void	ft_strdel(char **as);
void	ft_strclr(char *s);
char	*ft_strnew(size_t size);
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char 	**ft_strsplit(char const *s, char c);
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);

/* -=-=-=-=-	MEMORY		=-=-=-=-=-=- */
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memalloc(size_t size);
void	ft_memdel(void **ap);
void	ft_bzero(void *s, size_t n);

/* -=-=-=-=-	FILES		=-=-=-=-=-=- */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putendl(char const *s);
void	ft_putendl_fd(char const *s, int fd);

/* -=-=-=-=-	LISTS		=-=-=-=-=-=- */

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

#endif
