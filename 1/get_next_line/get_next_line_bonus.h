/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunajed <mmunajed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:41:53 by Melovi            #+#    #+#             */
/*   Updated: 2024/10/12 10:21:10 by mmunajed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define FD_LIMIT 4096

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

size_t	ft_strlen(char *s);
char	*get_next_line(int fd);
char	*ft_strdup(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
void	fill_str(char *res, char *s1, char *s2);

char	*ft_strchr(char *s, int c);
char	*set_line(char *line);
char	*fill_line_buffer(int fd, char *leftover, char *buffer);

#endif
