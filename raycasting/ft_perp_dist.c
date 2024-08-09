/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perp_dist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:26:44 by dabi-rac          #+#    #+#             */
/*   Updated: 2024/08/09 12:28:36 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_perp_dist(t_program *program)
{
	if (program->ray->side == 0)
		program->ray->perp_wall_dist = (program->ray->side_dist->x
				- program->ray->delta_dist->x);
	else
		program->ray->perp_wall_dist = (program->ray->side_dist->y
				- program->ray->delta_dist->y);
	program->ray->line_height = (int)(WINDOW_HEIGHT
			/ program->ray->perp_wall_dist);
	program->ray->draw_start = -program->ray->line_height
		/ 2 + WINDOW_HEIGHT / 2;
	if (program->ray->draw_start < 0)
		program->ray->draw_start = 0;
	program->ray->draw_end = program->ray->line_height
		/ 2 + WINDOW_HEIGHT / 2;
	if (program->ray->draw_end >= WINDOW_HEIGHT)
		program->ray->draw_end = WINDOW_HEIGHT - 1;
}

void	my_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*dst;

	dst = image->img_ptr + (y * image->line_len + x * (image->bpx / 8));
	*(unsigned int *)dst = color;
}
