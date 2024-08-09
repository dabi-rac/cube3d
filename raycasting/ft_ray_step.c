/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_step.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:15:46 by sgasperi          #+#    #+#             */
/*   Updated: 2024/08/09 12:28:37 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

//ray direction init
void	ft_ray_step_init2(t_program *program)
{
	if (program->start_dir == 'E')
	{
		program->player_nstep.x = -1;
		program->player_nstep.y = 0;
		program->camera_plane.x = 0;
		program->camera_plane.y = -0.66;
		program->start_dir = '0';
	}
	else if (program->start_dir == 'W')
	{
		program->player_nstep.x = 1;
		program->player_nstep.y = 0;
		program->camera_plane.x = 0;
		program->camera_plane.y = 0.66;
		program->start_dir = '0';
	}
}

void	ft_ray_step_init(t_program *program)
{
	program->ray->map_x = (int)program->player_pos.x;
	program->ray->map_y = (int)program->player_pos.y;
	if (program->start_dir == 'N')
	{
		program->player_nstep.x = 0;
		program->player_nstep.y = 1;
		program->camera_plane.x = -0.66;
		program->camera_plane.y = 0;
		program->start_dir = '0';
	}
	else if (program->start_dir == 'S')
	{
		program->player_nstep.x = 0;
		program->player_nstep.y = -1;
		program->camera_plane.x = 0.66;
		program->camera_plane.y = 0;
		program->start_dir = '0';
	}
	ft_ray_step_init2(program);
}

//ray direction calculation and DDA algorithm implementation
void	ft_ray_step(t_program *program, int i)
{
	program->camera_x = 2 * i / (double)WINDOW_WIDTH - 1;
	program->ray->dir->x = program->player_nstep.x
		+ program->camera_plane.x * program->camera_x;
	program->ray->dir->y = program->player_nstep.y
		+ program->camera_plane.y * program->camera_x;
	program->ray->map_x = (int)program->player_pos.x;
	program->ray->map_y = (int)program->player_pos.y;
	program->ray->hit = 0;
	if (program->ray->dir->x == 0)
		program->ray->delta_dist->x = 1e30;
	else
		program->ray->delta_dist->x = fabs(1 / program->ray->dir->x);
	if (program->ray->dir->y == 0)
		program->ray->delta_dist->y = 1e30;
	else
		program->ray->delta_dist->y = fabs(1 / program->ray->dir->y);
	ft_ray_step_calc(program);
	ft_ray_dda(program);
}
