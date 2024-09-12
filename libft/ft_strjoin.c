#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	char	*string;
	size_t	size;

	str1 = (char *)s1;
	str2 = (char *)s2;
	if (!s1)
		return (ft_strdup(s1));
	if (!s2)
		return (ft_strdup(s2));
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	string = ft_memalloc(size);
	if (!string)
		return (NULL);
	ft_strcpy(string, str1);
	ft_strcat(string, str2);
	return (string);
}
