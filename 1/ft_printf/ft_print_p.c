/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Melovi <Melovi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:55:45 by Melovi            #+#    #+#             */
/*   Updated: 2024/11/05 18:11:05 by Melovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*new_string(unsigned long value, int *strlen)
{
	unsigned long	temp;
	char			*str;
	int				index;

	index = 0;
	temp = value;
	while (temp != 0)
	{
		temp = temp / 16;
		index++;
	}
	str = ft_calloc(index + 1, sizeof(char));
	if (!str)
		return (NULL);
	*strlen = index - 1;
	return (str);
}

int	ft_put_pointer(unsigned long value, int ascii)
{
	unsigned long	temp;
	char			*print;
	int				*ptr;
	int				i;

	ptr = &i;
	temp = value;
	print = new_string(value, ptr);
	if (!print)
		return (-1);
	while (temp != 0 && i-- >= 0)
	{
		if ((temp % 16) < 10)
			print[i + 1] = (temp % 16) + 48;
		else
			print[i + 1] = (temp % 16) + ascii;
		temp = temp / 16;
	}
	i = ft_strlen(print);
	i = i + ft_put_str("0x");
	ft_putstr_fd(print, 1);
	free(print);
	if (value == 0)
		i += ft_put_char('0');
	return (i);
}
