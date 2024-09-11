#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*psrc;
	unsigned char	*pdest;

	if (src == dest)
		return (dest);
	psrc = (const unsigned char *)src;
	pdest = (unsigned char *)dest;

	if ((psrc < pdest) && (psrc + n) > pdest)
	{
		while (n--)
			*(pdest + n) = *(psrc + n);
	}
	else
	{
		while (n--)
		{
			*pdest = *psrc;
			pdest++;
			psrc++;
		}
	}
	return (dest);
}
