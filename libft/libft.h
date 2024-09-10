#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

/* -=-=-=-=- 	NUMBERS		-=-=-=-=-=- */
int		ft_atoi(const char *str);

/* -=-=-=-=- 	CHARS		-=-=-=-=-=- */
int		ft_isprint(int c);
int		ft_isascii(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
void	ft_putchar(char c);

/* -=-=-=-=-	STRINGS		=-=-=-=-=-=- */
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strcat(char *dest, char *src);
char	*ft_strncat(char *dest, char *src, int nb);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strstr(char *str, char *to_find);
void	ft_putstr(char const *s);

/* -=-=-=-=-	MEMORY		=-=-=-=-=-=- */
int		memcmp(const void *s1, const void *s2, size_t n);
void	*memmove(void *dest, const void *src, size_t n);
void	*memchr(const void *s, int c, size_t n);
void	*memccpy(void *dest, const void *src, int c, size_t n);
void	*memcpy(void *dest, const void *src, size_t n);
void	*memset(void *s, int c, size_t n);
void	bzero(void *s, size_t n);

/* -=-=-=-=-	FILES		=-=-=-=-=-=- */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* -=-=-=-=-	LISTS		=-=-=-=-=-=- */

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

#endif
