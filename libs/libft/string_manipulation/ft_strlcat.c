/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 09:52:23 by sgasperi          #+#    #+#             */
/*   Updated: 2023/01/27 15:06:02 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dlen;

	i = 0;
	j = 0;
	if (!dest && !src)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	while (dest[j] != '\0' && j < size)
		j++;
	dlen = j;
	while (src[i] != '\0' && (i + 1 + dlen) < size)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	if (dlen != size)
		dest[j] = '\0';
	return (dlen + ft_strlen(src));
}
