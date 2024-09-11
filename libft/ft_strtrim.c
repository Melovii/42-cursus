#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*string;
	size_t	start;
	size_t	end;
	size_t	size;

	start = 0;
	while (ft_isspace(s[start]))
		start++;
	end = ft_strlen(s) - 1;
	while (end > start && ft_isspace(s[end]))
		end --;
	size = end - start;
	string = ft_strnew(size + 1);
	if (!string)
		return (NULL);
	ft_strncpy(string, (char *)s + start, size);
	return (string);
}
