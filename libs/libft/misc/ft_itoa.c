/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:36:02 by sgasperi          #+#    #+#             */
/*   Updated: 2023/01/27 10:23:10 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

static unsigned int	ft_numlen(long int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	num;
	int			i;
	int			j;

	num = (long int) n;
	i = ft_numlen(num);
	j = -1;
	str = (char *)malloc((sizeof(char) * (i + 1)));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
		j = 0;
	}
	while (i > j)
	{
		str[i] = 48 + (num % 10);
		num = num / 10;
		i--;
	}
	return (str);
}
