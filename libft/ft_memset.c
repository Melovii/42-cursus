#include "libft.h"

void	*memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	ch;

	ch = (unsigned char)c;
	str = (unsigned char *)s;
	while (n)
	{
		*str = ch;
		str++;
	}
	return (s);
}
