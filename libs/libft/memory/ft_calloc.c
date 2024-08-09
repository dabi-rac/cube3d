/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgasperi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:06:14 by sgasperi          #+#    #+#             */
/*   Updated: 2023/01/27 16:07:25 by sgasperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*cal;

	cal = (void *)malloc(size * count);
	if (!cal || (count == SIZE_MAX && size == SIZE_MAX))
		return (0);
	ft_bzero(cal, (size * count));
	return (cal);
}
