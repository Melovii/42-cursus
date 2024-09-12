#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (!s || start >= ft_strlen(s))
		return (NULL);
	substr = ft_strnew(len + 1);
	if (!substr)
		return (NULL);
	substr = ft_strncpy(substr, (char *)s + start, len);
	return (substr);
}
