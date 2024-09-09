#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned char	ch;
	char			*ptr;
	size_t			index;

	index = ft_strlen(str);
	ch = c;
	ptr = (char *)str + index;
	if (ch == '\0')
		return (ptr++);
	while (ptr >= str)
	{
		if (*ptr == ch)
			return (ptr);
		ptr--;
	}
	ptr = NULL;
	return (ptr);
}
