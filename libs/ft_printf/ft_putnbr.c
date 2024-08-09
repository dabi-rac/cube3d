/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:19:33 by sgasperi          #+#    #+#             */
/*   Updated: 2023/02/21 10:26:57 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
		return (ft_putstr("-2147483648"));
	else if (nb == 2147483647)
		return (ft_putstr("2147483647"));
	if (nb < 0)
	{
		i += ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 0 && nb <= 9)
		i += ft_putchar(nb + 48);
	else
	{
		i += ft_putnbr(nb / 10);
		i += ft_putchar((nb % 10) + 48);
	}
	return (i);
}
