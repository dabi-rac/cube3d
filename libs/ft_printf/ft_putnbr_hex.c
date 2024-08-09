/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:23:14 by sgasperi          #+#    #+#             */
/*   Updated: 2023/02/21 09:23:50 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned int nb, const char *map)
{
	int	i;

	i = 0;
	if (nb >= 16)
	{
		i += ft_putnbr_hex(nb / 16, map);
	}
	i += ft_putchar(map[nb % 16]);
	return (i);
}
