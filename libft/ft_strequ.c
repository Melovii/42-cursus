#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	char const	*ps1;
	char const	*ps2;
	size_t		i;

	if (!s1 || !s2)
		return (s1 == s2);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	ps1 = (char const *)s1;
	ps2 = (char const *)s2;
	i = 0;
	while (ps1[i] && ps2[i])
	{
		if (ps1[i] != ps2[i])
			return (0);
		i++;
	}
	return (1);
}
