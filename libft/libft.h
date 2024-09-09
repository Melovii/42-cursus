#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

/* -=-=-=-=- 	NUMBERS		-=-=-=-=-=- */
int		ft_atoi(const char *str);

/* -=-=-=-=- 	CHARS		-=-=-=-=-=- */
int		ft_isprint(char c);
int		ft_isascii(char c);
int		ft_isalpha(char c);
int		ft_isdigit(char c);
int		ft_isalnum(char c);
int		ft_toupper(char c);
int		ft_tolower(char c);

/* -=-=-=-=-	STRINGS		=-=-=-=-=-=- */
size_t	ft_strlen(const char *str);

/* -=-=-=-=-	MEMORY		=-=-=-=-=-=- */

/* -=-=-=-=-	FILES		=-=-=-=-=-=- */

/* -=-=-=-=-	LISTS		=-=-=-=-=-=- */

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

#endif