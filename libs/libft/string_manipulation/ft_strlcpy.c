/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:28:05 by sgasperi          #+#    #+#             */
/*   Updated: 2023/01/25 09:26:19 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while (src[i] && i < (n - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}
