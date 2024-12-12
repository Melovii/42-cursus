/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunajed <mmunajed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:19:12 by mmunajed          #+#    #+#             */
/*   Updated: 2024/12/12 15:19:12 by mmunajed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_put_c(va_list args);
int	ft_put_s(va_list args);
int	ft_put_u(va_list args, char *base);
int	ft_put_n(va_list args, char *base);
int	ft_put_p(va_list args, char *base);

#endif
