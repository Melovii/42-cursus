/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:51:16 by marvin            #+#    #+#             */
/*   Updated: 2024/12/05 10:51:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_type(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == '\0')
		return (count);
	if (specifier == '%')
		count += ft_putchar('%');
	else if (specifier == 'c')
		count += ft_put_c(args);
	else if (specifier == 's')
		count += ft_put_s(args);
	else if (specifier == 'd' || specifier == 'i')
		count += ft_put_n(args, "0123456789");
	else if (specifier == 'u')
		count += ft_put_u(args, "0123456789");
	else if (specifier == 'x')
		count += ft_put_u(args, "0123456789abcdef");
	else if (specifier == 'X')
		count += ft_put_u(args, "0123456789ABCDEF");
	else if (specifier == 'p')
		count += ft_put_p(args, "0123456789abcdef");
	else
		count += ft_putchar(specifier);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_handle_type(format[i], args);	
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
