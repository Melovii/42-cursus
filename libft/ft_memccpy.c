#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	const unsigned char		*psrc;
	unsigned char			*pdest;
	unsigned char			ch;

	psrc = (const unsigned char *)src;
	pdest = (unsigned char *)dest;
	ch = c;
	while (n != 0)
	{
		*pdest = *psrc;
		pdest++;
		if (*psrc == ch)
			return (pdest);
		psrc++;
		n--;
	}
	return (NULL);
}
