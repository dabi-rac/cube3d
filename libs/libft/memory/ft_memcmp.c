/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:05:28 by sgasperi          #+#    #+#             */
/*   Updated: 2023/01/27 14:26:02 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*stringa1;
	unsigned char	*stringa2;

	stringa1 = (unsigned char *)s1;
	stringa2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (stringa1[i] != stringa2[i])
			return (stringa1[i] - stringa2[i]);
		i++;
	}
	return (0);
}
