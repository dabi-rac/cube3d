/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 09:21:22 by sgasperi          #+#    #+#             */
/*   Updated: 2023/02/21 09:22:02 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)

{
	int	len;

	len = 0;
	if (!str)
		return (write (1, "(null)", 6));
	while (str[len])
	{
		ft_putchar(str[len]);
		len++;
	}
	return (len);
}
