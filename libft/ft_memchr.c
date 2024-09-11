#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char		*pstr;
	unsigned char			ch;
	size_t					index;

	pstr = (unsigned const char *)s;
	ch = (unsigned char)c;
	index = 0;
	while (index < n)
	{
		if (pstr[index] == ch)
			return ((void *)(pstr + index));
		index++;
	}
	return (NULL);
}
