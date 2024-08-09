/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:05:46 by sgasperi          #+#    #+#             */
/*   Updated: 2023/01/27 14:48:30 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
		return ((char *)str);
	while (i < len && str[i] != '\0')
	{
		while (str[i + j] == to_find[j] && str[i + j] != '\0' && (i + j) < len)
			j++;
		if (to_find[j] == '\0')
			return ((char *)str + i);
		i++;
		j = 0;
	}
	return (0);
}
