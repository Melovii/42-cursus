/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Melovi <Melovi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:58:22 by Melovi            #+#    #+#             */
/*   Updated: 2024/11/05 18:10:38 by Melovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_type(char type, va_list args)
{
	if (type == 'c')
		return (ft_put_char(va_arg(args, int)));
	else if (type == 's')
		return (ft_put_str(va_arg(args, char *)));
	else if (type == 'p')
		return (ft_put_pointer(va_arg(args, unsigned long), 87));
	else if (type == 'd' || type == 'i')
		return (ft_put_int(va_arg(args, int)));
	else if (type == 'u')
		return (ft_put_unsigned(va_arg(args, unsigned int)));
	else if (type == 'x')
		return (ft_put_hex(va_arg(args, unsigned int), 87));
	else if (type == 'X')
		return (ft_put_hex(va_arg(args, unsigned int), 55));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
				count += ft_put_char('%');
			else if (ft_strchr("cspdiuxX%", format[i]))
				count += handle_type(format[i], args);
			else if (format[i] != '\0')
				count += ft_put_char(format[i]);
		}
		else
			count += ft_put_char(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
