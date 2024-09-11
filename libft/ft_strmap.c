#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*string;
	size_t	i;

	if (!s || !f)
		return NULL;
	i = ft_strlen(s);
	string = malloc((i + 1) * sizeof(char));
	if (!string)
		return (NULL);
	i = 0;
	while (s[i])
	{
		string[i] = f(s[i]);
		i++;
	}
	string[i] = '\0';
	return (string);
}
