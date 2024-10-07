/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunajed <mmunajed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:53:10 by mmunajed          #+#    #+#             */
/*   Updated: 2024/10/07 15:09:03 by mmunajed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[n] = '\0';
		i++;
	}
	return (dest);
}

static char	*ft_strnew(size_t size)
{
	char	*string;

	string = (char *)malloc((size + 1) * sizeof(char));
	if (!string)
		return (NULL);
	ft_memset(string, 0, size + 1);
	return (string);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (!s || start >= ft_strlen(s))
		return (NULL);
	substr = ft_strnew(len + 1);
	if (!substr)
		return (NULL);
	substr = ft_strncpy(substr, (char *)s + start, len);
	return (substr);
}
