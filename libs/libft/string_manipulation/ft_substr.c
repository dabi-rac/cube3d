/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:20:44 by sgasperi          #+#    #+#             */
/*   Updated: 2023/01/27 09:59:00 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*c;
	unsigned int	i;
	unsigned int	j;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = (unsigned int)len;
	if (ft_strlen((char *)s) <= len)
		c = (char *) malloc(ft_strlen((char *)s) + 1);
	else
		c = (char *) malloc(j + 1);
	if (!c)
		return (NULL);
	if (!((unsigned int) ft_strlen((char *)s) < start))
	{
		while (s[i] != '\0' && i < j)
		{
			c[i] = s[start];
			i++;
			start++;
		}
	}
	c[i] = '\0';
	return (c);
}
