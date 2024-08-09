/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_paddress.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:24:01 by sgasperi          #+#    #+#             */
/*   Updated: 2023/02/21 10:48:35 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_paddress(unsigned long p, const char *str)
{
	int	i;

	i = 2;
	ft_putchar('0');
	ft_putchar('x');
	i += ft_putnbr_hex_address(p, str);
	return (i);
}
