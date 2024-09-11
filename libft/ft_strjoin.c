#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	size;

	if (!s1)
		return (ft_strdup(s1));
	if (!s2)
		return (ft_strdup(s2));

	size = strlen(s1) + strlen(s2) + 1;
	string = ft_malloc(size);
	if (!string)
		return (NULL);

	strcpy(string, s1);
	strcat(string, s2);
	return (string);
}
