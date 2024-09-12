#include <stdlib.h>
#include <stdio.h>

int	char_is_separator(char c, char charset)
{
	if (c == charset || c == '\0')
		return (1);
	return (0);
}

int	count_words(char *str, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (char_is_separator(str[i], c) == 0
			&& (i == 0 || char_is_separator(str[i - 1], c) == 1))
			words++;
		i++;
	}
	return (words);
}

void	write_word(char *dest, char *from, char c)
{
	int	i;

	i = 0;
	while (char_is_separator(from[i], c) == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

void	write_split(char **split, char *str, char c)
{
	int	word;
	int	i;
	int	j;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (char_is_separator(str[i], c) == 1)
			i++;
		else
		{
			j = 0;
			while (char_is_separator(str[i + j], c) == 0)
				j++;
			split[word] = (char *)malloc(sizeof(char) * (j + 1));
			write_word(split[word], str + i, c);
			i += j;
			word++;
		}
	}
}

char	**ft_strsplit(char const *s, char c)
{
	char	**strings;
	int		words;

	words = count_words((char *)s, c);
	strings = (char **)malloc(sizeof(char *) * (words + 1));
	if (strings == NULL)
		return (NULL);
	strings[words] = 0;
	write_split(strings, (char *)s, c);
	return (strings);
}
