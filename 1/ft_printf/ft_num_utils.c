/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunajed <mmunajed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:19:01 by mmunajed          #+#    #+#             */
/*   Updated: 2024/12/12 15:19:01 by mmunajed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	ft_number_based(unsigned long nbr, char *base)
{
	int				count;
	unsigned int	base_length;

	count = 0;
	base_length = ft_strlen(base);
	if (nbr >= base_length)
		count += ft_number_based(nbr / base_length, base);
	ft_putchar(base[nbr % base_length]);
	return (count + 1);
}

int	ft_put_n(va_list args, char *base)
{
	long	nbr;
	int		count;

	count = 0;
	nbr = va_arg(args, int);
	if (nbr < 0)
	{
		nbr = -nbr;
		count += ft_putchar('-');
	}
	count += ft_number_based(nbr, base);
	return (count);
}

int	ft_put_u(va_list args, char *base)
{
	int				count;
	unsigned int	nbr;

	count = 0;
	nbr = va_arg(args, unsigned int);
	count += ft_number_based(nbr, base);
	return (count);
}

int	ft_put_p(va_list args, char *base)
{
	int				count;
	void			*check;
	unsigned long	nbr;

	check = va_arg(args, void *);
	if (!check)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	nbr = (unsigned long)check;
	write(1, "0x", 2);
	count = 2;
	count += ft_number_based(nbr, base);
	return (count);
}
