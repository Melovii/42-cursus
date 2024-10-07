/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunajed <mmunajed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:50:17 by mmunajed          #+#    #+#             */
/*   Updated: 2024/10/07 17:21:32 by mmunajed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(long int nbr)
{
	int	len;

	if (nbr <= 0)
		len = 1;
	else
		len = 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

static int	ft_abs(long int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

static char	*ft_strnew(size_t size)
{
	char	*string;

	string = (char *)malloc((size + 1));
	if (!string)
		return (NULL);
	ft_memset(string, 0, size + 1);
	return (string);
}

char	*ft_itoa(int n)
{
	char	*string;
	int		len;
	int		sign;

	if (n < 0)
		sign = -1;
	else
		sign = 1;
	len = ft_numlen(n);
	string = (char *)ft_strnew(len + 1);
	if (!string)
		return (NULL);
	string[len] = '\0';
	len--;
	while (len >= 0)
	{
		string[len] = '0' + ft_abs(n % 10);
		n = ft_abs(n / 10);
		len--;
	}
	if (sign == -1)
		string[0] = '-';
	return (string);
}
