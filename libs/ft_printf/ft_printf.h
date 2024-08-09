/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:32:31 by sgasperi          #+#    #+#             */
/*   Updated: 2023/02/21 09:13:16 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_types(const char *str, int i, va_list type);
int		ft_putchar(char str);
int		ft_putnbr(int nb);
int		ft_putnbr_uns(unsigned int nb);
int		ft_putstr(char *str);
int		ft_putnbr_hex(unsigned int nb, const char *map);
int		ft_putnbr_hex_address(unsigned long nb, const char *map);
int		ft_putnbr_paddress(unsigned long p, const char *str);
#endif
