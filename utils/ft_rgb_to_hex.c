/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:13:08 by sgasperi          #+#    #+#             */
/*   Updated: 2024/08/09 12:28:46 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	ft_rgb_to_hex(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	get_pixel(t_image *image, int x, int y)
{
	char	*dst;

	if (x < 0 || y < 0)
		return (1);
	dst = image->img_ptr + (y * image->line_len + x * (image->bpx / 8));
	return (*(unsigned int *)dst);
}

int	ft_array_int_len(int *array)
{
	int	i;

	i = 0;
	while (array[i] != '\0')
		i++;
	return (i);
}

void	color_parse(t_program *program, int	*rgb, char c)
{
	if (c == 'F')
	{
		program->floor->r = check_colors(rgb[0]);
		program->floor->g = check_colors(rgb[1]);
		program->floor->b = check_colors(rgb[2]);
	}
	else if (c == 'C')
	{
		program->ceiling->r = check_colors(rgb[0]);
		program->ceiling->g = check_colors(rgb[1]);
		program->ceiling->b = check_colors(rgb[2]);
	}
}
