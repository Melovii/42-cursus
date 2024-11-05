/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Melovi <Melovi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:28:37 by Melovi            #+#    #+#             */
/*   Updated: 2024/11/05 18:08:42 by Melovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*new_string(unsigned int value, int *strlen)
{
	int				i;
	unsigned int	temp;
	char			*str;

	i = 0;
	temp = value;
	while (temp != 0)
	{
		temp /= 16;
		i++;
	}
	str = ft_calloc(i + 1, sizeof(char));
	*strlen = i - 1;
	return (str);
}

int	ft_put_hex(unsigned int value, int ascii)
{
	unsigned int	temp;
	char			*print;
	int				i;
	int				*ptr;

	ptr = &i;
	temp = value;
	print = new_string(value, ptr);
	if (!print)
		return (-1);
	while (temp != 0)
	{
		if ((temp % 16) < 10)
			print[i] = (temp % 16) + 48;
		else
			print[i] = (temp % 16) + ascii;
		temp /= 16;
		i--;
	}
	ft_putstr_fd(print, 1);
	i = ft_strlen(print);
	free(print);
	if (value == 0)
		i += ft_put_char('0');
	return (i);
}
