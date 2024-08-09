/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:00:41 by sgasperi          #+#    #+#             */
/*   Updated: 2023/01/27 14:35:28 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

static size_t	get_word(const char *string_to_split, char separator)
{
	size_t	number_of_words;

	number_of_words = 0;
	while (*string_to_split)
	{
		if (*string_to_split != separator)
		{
			number_of_words++;
			while (*string_to_split && *string_to_split != separator)
				string_to_split++;
		}
		else
			string_to_split++;
	}
	return (number_of_words);
}

char	**ft_split(const char *s, char c)
{
	char	**number_of_words;
	size_t	i;
	size_t	len;

	if (!s)
		return (0);
	i = 0;
	number_of_words = malloc(sizeof(char *) * (get_word(s, c) + 1));
	if (!number_of_words)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			number_of_words[i++] = ft_substr(s - len, 0, len);
		}
		else
			++s;
	}
	number_of_words [i] = 0;
	return (number_of_words);
}
