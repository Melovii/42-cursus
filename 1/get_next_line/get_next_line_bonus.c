#include "get_next_line_bonus.h"

// ! consider making this static char/
// !! ADD HEADERS BROTHERRR
// TODO: ABOVE ^^^

char	*firstline(int fd, char *buffer)
{
	char	*buf;
	int		char_read;

	char_read = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!ft_found_newline(buffer) && char_read != 0)
	{
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read == -1)
		{
			free(buffer);
			free(buf);
			return (NULL);
		}
		buf[char_read] = '\0';
		buffer = ft_strjoin(buffer, buf);
	}
	free(buf);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buf[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf[fd] = firstline(fd, buf[fd]);
	if (buf[fd] == NULL)
		return (NULL);
	line = ft_extract_line(buf[fd]);
	buf[fd] = ft_trim_buffer(buf[fd]);
	return (line);
}
