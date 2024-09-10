#include "libft.h"

void	*memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*pdest;
	const char		*psrc;

	if (!psrc && !pdest)
		return (0);
	pdest = (unsigned char *)dest;
	psrc = (const char *)src;
	while (n != 0)
	{
		*pdest = *psrc;
		psrc++;
		pdest++;
		n--;
	}
	return (dest);
}
