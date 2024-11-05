/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Melovi <Melovi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 13:23:48 by mmunajed          #+#    #+#             */
/*   Updated: 2024/11/05 17:52:54 by Melovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_put_char(int c);
int		ft_put_int(int n);
int		ft_put_pointer(unsigned long value, int ch);
int		ft_put_str(char *str);
int		ft_put_unsigned(unsigned int n);
int		ft_put_hex(unsigned int value, int ch);

#endif
