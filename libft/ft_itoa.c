#include "libft.h"

char	*ft_itoa(int nbr)
{
	char	*string;
	int		len;
	int		sign;

	if (nbr < 0)
		sign = -1;
	else
		sign = 1;
	len = ft_numlen(nbr);
	string = (char *)ft_strnew(len + 1);
	if (!string)
		return (NULL);
	string[len] = '\0';
	len--;
	while (len >= 0)
	{
		string[len] = '0' + ft_abs(nbr % 10);
		nbr = ft_abs(nbr / 10);
		len--;
	}
	if (sign == -1)
		string[0] = '-';
	return (string);
}
