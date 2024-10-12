/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunajed <mmunajed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:41:32 by Melovi            #+#    #+#             */
/*   Updated: 2024/10/12 10:21:05 by mmunajed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(char *s, int c)
{
	unsigned int	i;
	char			cc;

	cc = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *) &s[i]);
	return (NULL);
}

char	*set_line(char *line_buffer)
{
	char	*leftover;
	ssize_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == 0 || line_buffer[1] == 0)
		return (NULL);
	leftover = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (*leftover == 0)
	{
		free(leftover);
		leftover = NULL;
	}
	line_buffer[i + 1] = 0;
	return (leftover);
}

char	*fill_line_buffer(int fd, char *leftover, char *buffer)
{
	ssize_t	read_bytes;
	char	*temp;

	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(leftover);
			return (NULL);
		}
		else if (read_bytes == 0)
			break ;
		buffer[read_bytes] = 0;
		if (!leftover)
			leftover = ft_strdup("");
		temp = leftover;
		leftover = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (leftover);
}

char	*get_next_line(int fd)
{
	static char	*leftover[FD_LIMIT];
	char		*buffer;
	char		*line;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(leftover[fd]);
		free(buffer);
		leftover[fd] = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = fill_line_buffer(fd, leftover[fd], buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	leftover[fd] = set_line(line);
	return (line);
}
