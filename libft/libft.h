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

/* -=-=-=-=-	MEMORY		=-=-=-=-=-=- */

/* -=-=-=-=-	FILES		=-=-=-=-=-=- */

/* -=-=-=-=-	LISTS		=-=-=-=-=-=- */

/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=- */

#endif