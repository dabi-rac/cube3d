/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:20:34 by sgasperi          #+#    #+#             */
/*   Updated: 2023/02/21 10:43:46 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_uns(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb > 9)
	{
		i += ft_putnbr(nb / 10);
		i += ft_putnbr(nb % 10);
	}
	else
	{
		i += ft_putchar(nb + 48);
	}
	return (i);
}
