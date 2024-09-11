#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*string;

	string = (char *)malloc((size + 1) * sizeof(char));
	if (!string)
		return (NULL);
	ft_memset(string, 0, size + 1);
	return (string);
}
