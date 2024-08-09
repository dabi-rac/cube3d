/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:11:48 by sgasperi          #+#    #+#             */
/*   Updated: 2023/02/21 10:57:08 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_types(const char *str, int i, va_list type)
{
	if (str[i] == 'c')
		return (ft_putchar(va_arg(type, int)));
	else if (str[i] == 's')
		return (ft_putstr(va_arg(type, char *)));
	else if (str[i] == 'p')
		return (ft_putnbr_paddress
			(va_arg(type, unsigned long), "0123456789abcdef"));
	else if (str[i] == 'i')
		return (ft_putnbr(va_arg(type, int)));
	else if (str[i] == 'd')
		return (ft_putnbr(va_arg(type, int)));
	else if (str[i] == 'u')
		return (ft_putnbr_uns(va_arg(type, int)));
	else if (str[i] == 'x')
		return (ft_putnbr_hex(va_arg(type, int), "0123456789abcdef"));
	else if (str[i] == 'X')
		return (ft_putnbr_hex(va_arg(type, int), "0123456789ABCDEF"));
	else if (str[i] == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i1;
	int		i2;
	va_list	args;

	i1 = 0;
	i2 = 0;
	va_start(args, str);
	if (!str)
		return (0);
	while (str[i1])
	{
		if (str[i1] == '%')
			i2 += ft_types(str, ++i1, args);
		else
		{
			write (1, &str[i1], 1);
			i2++;
		}
		i1++;
	}
	va_end(args);
	return (i2);
}
