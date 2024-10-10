/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunajed <mmunajed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:56:02 by mmunajed          #+#    #+#             */
/*   Updated: 2024/10/10 14:52:53 by mmunajed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill_line_buffer(int fd, char *leftover, char *buffer);
static char	*set_line(char *line_buffer);

// * Reads from a file descriptor and fills a buffer with the read data.
static char	*fill_line_buffer(int fd, char *leftover, char *buffer)
{
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(leftover);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = 0;
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

// * Constructs a line from the buffer filled with read data.
static char	*set_line(char *line_buffer)
{
	char	*leftover;
	ssize_t	i;

	i = 0;
	while (line_buffer[i] != '\n' || line_buffer[i] != '\0')
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

// * Function that returns next line from FD
char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
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

// ! FOR IT TO ACCEPT STANDARD INPUT WHICH IS 0
	// if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)

// ! derefernce leftover if it's empty cause it's gone, basically reset/free it
	// if (*leftover == 0)
	// {
	// 	free(leftover);
	// 	leftover = NULL;
	// }

// ! TO TAKE -1
	// ssize_t i;

// ! static n file-local functions should be stated at the top of .c files
// ! not in the header file
	// static char	*fill_line_buffer(int fd, char *leftover, char *buffer);
	// static char	*set_line(char *line_buffer);