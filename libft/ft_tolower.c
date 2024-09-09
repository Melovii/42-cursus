#include "libft.h"

int	ft_toupper(char c)
{
	if (c >= 'a' && c <= 'z')
		c += 32;
	return (c);
}
