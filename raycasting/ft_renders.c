/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renders.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:12:38 by sgasperi          #+#    #+#             */
/*   Updated: 2024/08/09 12:28:39 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_render_floor_ceiling(t_program *program)
{
	int	x;
	int	y;

	y = WINDOW_HEIGHT / 2 + 1;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(program->image, WINDOW_WIDTH - x,
				y, program->floor->hex);
			my_mlx_pixel_put(program->image, WINDOW_WIDTH - x,
				WINDOW_HEIGHT - y - 1, program->ceiling->hex);
			x++;
		}
		y++;
	}
}

void	ft_render_wall(t_program *program)
{
	int	x;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		ft_ray_step_init(program);
		ft_ray_step(program, x);
		if (program->ray->side == 0)
			program->wall->wall_x = program->player_pos.y
				+ program->ray->perp_wall_dist * program->ray->dir->y;
		else
			program->wall->wall_x = program->player_pos.x
				+ program->ray->perp_wall_dist * program->ray->dir->x;
		program->wall->wall_x -= floor((program->wall->wall_x));
		program->wall->tex_x = (int)(program->wall->wall_x * (double)TEXWIDTH);
		if (program->ray->side == 0 && program->ray->dir->x > 0)
			program->wall->tex_x = TEXWIDTH - program->wall->tex_x - 1;
		if (program->ray->side == 1 && program->ray->dir->y < 0)
			program->wall->tex_x = TEXWIDTH - program->wall->tex_x - 1;
		program->wall->step = 1.0 * TEXHEIGHT / program->ray->line_height;
		program->wall->tex_pos = (program->ray->draw_start - WINDOW_HEIGHT / 2
				+ program->ray->line_height / 2) * program->wall->step;
		ft_render_y(program, x);
		x++;
	}
}

void	ft_render_y(t_program *program, int x)
{
	int		draw_start_y;
	t_wall	*data;

	data = program->wall;
	draw_start_y = program->ray->draw_start;
	while (draw_start_y < program->ray->draw_end)
	{
		data->tex_y = (int)data->tex_pos & (TEXHEIGHT - 1);
		data->tex_pos += data->step;
		if (program->ray->hit == 1)
			ft_draw_wall(program, data, x, draw_start_y);
		draw_start_y++;
	}
}

void	ft_draw_wall(t_program *program, t_wall *data, int x, int y)
{
	if (program->ray->side != 0 && program->ray->step_y == -1)
	{
		my_mlx_pixel_put(program->image, WINDOW_WIDTH - x, y,
			get_pixel(program->north_wall, data->tex_x, data->tex_y));
	}
	else if (program->ray->side != 0 && program->ray->step_y == 1)
	{
		my_mlx_pixel_put(program->image, WINDOW_WIDTH - x, y,
			get_pixel(program->south_wall, data->tex_x, data->tex_y));
	}
	else if (program->ray->step_x == -1)
	{
		my_mlx_pixel_put(program->image, WINDOW_WIDTH - x, y,
			get_pixel(program->west_wall, data->tex_x, data->tex_y));
	}
	else if (program->ray->step_x == 1)
	{
		my_mlx_pixel_put(program->image, WINDOW_WIDTH - x, y,
			get_pixel(program->east_wall, data->tex_x, data->tex_y));
	}
}

int	ft_render(t_program *program)
{
	if (program->moves->w == 1 || program->moves->s == 1)
		go_forward(program);
	if (program->moves->a == 1 || program->moves->d == 1)
		go_side(program);
	if (program->moves->l == 1 || program->moves->r == 1)
		pov_rotate(program);
	ft_render_floor_ceiling(program);
	ft_render_wall(program);
	mlx_put_image_to_window(program->ptr, program->window,
		program->image->image, 0, 0);
	return (0);
}
