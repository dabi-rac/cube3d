/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:14:02 by sgasperi          #+#    #+#             */
/*   Updated: 2023/01/25 13:32:50 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*source;
	char	*dest;
	size_t	i;

	dest = (char *)dst;
	source = (char *)src;
	i = 0;
	if (dest > source)
	{
		while (len-- > 0)
		{
			dest[len] = source[len];
		}
	}
	else if (!(dest) && !(src))
		return (NULL);
	else
	{
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	}
	return (dst);
}
