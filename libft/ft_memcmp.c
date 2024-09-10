#include "libft.h"

int	memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*str1;
	const char	*str2;
	size_t		i;

	if (n == 0)
		return (0);
	str1 = (const char *)s1;
	str2 = (const char *)s2;
	i = 0;
	while (str1[i] == str2[i] && (i < n - 1))
		i++;
	return (str1[i] - str2[i]);
}
