/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunajed <mmunajed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:56:02 by mmunajed          #+#    #+#             */
/*   Updated: 2024/10/10 14:03:15 by mmunajed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// * Reads from a file descriptor and fills a buffer with the read data.
static char	*fill_line_buffer(int fd, char *leftover, char *buffer)
{
	char	*temp;
	int		bytes;

	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes < 0)
		return (NULL);
	if (bytes == 0)
		return (leftover);
	while (*buffer)
	{
		if (*buffer == '\n' || *buffer == '\0')
			break ;
		if (*leftover == NULL)
		{
			leftover = ft_strdup(buffer);
		}
		else
		{
			temp = ft_strjoin(buffer, leftover);
			free(leftover);
			leftover = temp;
		}
		buffer++;
	}
	return (leftover);
}

// * Constructs a line from the buffer filled with read data.
static char	*set_line(char *line_buffer)
{
	char	*leftover;

	while (*line_buffer != '\n' || *line_buffer != '\0')
	{
		line_buffer++;
	}
	*line_buffer = '\0';
	leftover = line_buffer + 1;
	return (leftover);
}

// * Function that returns next line from FD
char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(leftover);
		free(buffer);
		leftover = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = fill_line_buffer(fd, leftover, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	leftover = set_line(line);
	return (line);
}

// ? reason behind leftover being static is to keep track of the leftover characters after each get_next_line call
// ? setline simply gets the leftover characters of the given 'line' parameter
// ? line_buffer + 1 because we want to move the 'leftover' pointer to the next character so we can process proceeding shit