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

/* -=-=-=-=-	STRINGS		=-=-=-=-=-=- */
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strdup(const char *s1);
char	*ft_strcat(char *dest, char *src);
char	*ft_strncat(char *dest, char *src, int nb);
char	*ft_strlcat(char *dst, const char *src, size_t dstsize);


/* -=-=-=-=-	MEMORY		=-=-=-=-=-=- */

/* -=-=-=-=-	FILES		=-=-=-=-=-=- */

/* -=-=-=-=-	LISTS		=-=-=-=-=-=- */

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

#endif