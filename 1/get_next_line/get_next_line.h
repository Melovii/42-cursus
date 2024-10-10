/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunajed <mmunajed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:06:26 by mmunajed          #+#    #+#             */
/*   Updated: 2024/10/10 14:52:04 by mmunajed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1042
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

// * FUNCTION PROTOTYPES
char	*get_next_line(int fd);

size_t	ft_strlen(const char *str);
void	fill_str(char *res, char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char *s1, char *s2);

#endif
