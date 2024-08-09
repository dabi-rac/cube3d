/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:36:18 by sgasperi          #+#    #+#             */
/*   Updated: 2023/01/26 11:28:02 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

char	*ft_strdup(const char *s1)
{
	char	*t;
	size_t	i;

	t = (char *)malloc(sizeof(char) * ft_strlen((char *)s1) + 1);
	i = 0;
	if (t == NULL)
		return (NULL);
	while (s1[i])
	{
		t[i] = s1[i];
		i++;
	}
	t[i] = '\0';
	return (t);
}
