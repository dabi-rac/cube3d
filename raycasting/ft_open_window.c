/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:07:14 by dabi-rac          #+#    #+#             */
/*   Updated: 2024/08/09 12:28:35 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	ft_open_window(t_program *program)
{
	program->window = mlx_new_window(program->ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "Cub3D");
	if (program->main_img_check == 0)
	{
		program->image = ft_calloc(1, sizeof(t_image));
		program->image->image = mlx_new_image(program->ptr,
				WINDOW_WIDTH, WINDOW_HEIGHT);
		program->image->img_ptr = mlx_get_data_addr(
				program->image->image, &program->image->bpx,
				&program->image->line_len, &program->image->endian);
		program->main_img_check = 1;
	}
	handle_move(program);
	return (0);
}

//ray step calculation for DDA algorithm implementation
void	ft_ray_step_calc(t_program *program)
{
	if (program->ray->dir->x < 0)
	{
		program->ray->step_x = -1;
		program->ray->side_dist->x = (program->player_pos.x
				- program->ray->map_x) * program->ray->delta_dist->x;
	}
	else
	{
		program->ray->step_x = 1;
		program->ray->side_dist->x = (program->ray->map_x + 1.0
				- program->player_pos.x) * program->ray->delta_dist->x;
	}
	if (program->ray->dir->y < 0)
	{
		program->ray->step_y = -1;
		program->ray->side_dist->y = (program->player_pos.y
				- program->ray->map_y) * program->ray->delta_dist->y;
	}
	else
	{
		program->ray->step_y = 1;
		program->ray->side_dist->y = (program->ray->map_y + 1.0
				- program->player_pos.y) * program->ray->delta_dist->y;
	}
}

//DDA algorithm implementation
void	ft_ray_dda(t_program *program)
{
	while (program->ray->hit == 0)
	{
		if (program->ray->side_dist->x < program->ray->side_dist->y)
		{
			program->ray->side_dist->x += program->ray->delta_dist->x;
			program->ray->map_x += program->ray->step_x;
			program->ray->side = 0;
		}
		else
		{
			program->ray->side_dist->y += program->ray->delta_dist->y;
			program->ray->map_y += program->ray->step_y;
			program->ray->side = 1;
		}
		program->ray->hit = program->map[program->ray->map_y]
		[program->ray->map_x] == '1';
		if (program->ray->hit == 1)
			break ;
	}
	ft_perp_dist(program);
}
