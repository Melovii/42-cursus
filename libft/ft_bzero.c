#include "libft.h"

void	bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n != 0)
	{
		*str = '\0';
		str++;
		n--;
	}
}
