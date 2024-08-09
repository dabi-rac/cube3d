/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_address.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:22:20 by sgasperi          #+#    #+#             */
/*   Updated: 2023/02/21 10:32:10 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex_address(unsigned long nb, const char *map)
{
	int	i;

	i = 0;
	if (nb >= 16)
	{
		i += ft_putnbr_hex_address(nb / 16, map);
	}
	i += ft_putchar(map[nb % 16]);
	return (i);
}
