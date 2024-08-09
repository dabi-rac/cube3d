/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:32:20 by dabi-rac          #+#    #+#             */
/*   Updated: 2024/08/09 12:32:20 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/cube3d.h"

int	check_colors(int colour_matrix)
{
	if (colour_matrix >= 0 && colour_matrix <= 255)
		return (colour_matrix);
	else
		return (-1);
}

int	check_tex_coords(t_program *program, t_image *img,
		char **tmp)
{
	int	h;
	int	w;

	h = 64;
	w = 64;
	if (tmp[1] != NULL
		&& tmp[1][ft_strlen(tmp[1]) - 1] == 'm'
		&& tmp[1][ft_strlen(tmp[1]) - 2] == 'p'
		&& tmp[1][ft_strlen(tmp[1]) - 3] == 'x'
		&& tmp[1][ft_strlen(tmp[1]) - 4] == '.')
	{
		img->image
			= mlx_xpm_file_to_image(program->ptr, tmp[1], &h, &w);
		if (!img->image)
		{
			printf("check_tex_coords");
			return (0);
		}
		img->img_ptr
			= mlx_get_data_addr(img->image, (&img->bpx), (&img->line_len),
				(&img->endian));
		return (1);
	}
	return (0);
}
