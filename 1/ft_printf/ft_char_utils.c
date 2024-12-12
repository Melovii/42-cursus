/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunajed <mmunajed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:18:56 by mmunajed          #+#    #+#             */
/*   Updated: 2024/12/12 15:18:56 by mmunajed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_put_c(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	return (ft_putchar(c));
}

int	ft_put_s(va_list args)
{
	int		count;
	int		i;
	char	*s;

	s = (va_arg(args, char *));
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	count = 0;
	i = 0;
	while (s[i])
	{
		count += ft_putchar(s[i]);
		i++;
	}
	return (count);
}
