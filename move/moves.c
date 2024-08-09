/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:42:12 by dabi-rac          #+#    #+#             */
/*   Updated: 2024/08/09 12:28:31 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	go_forward(t_program *program)
{
	float	next_x;
	float	next_y;

	next_x = program->player_pos.x + program->player_nstep.x
		* program->moves->move_speed;
	next_y = program->player_pos.y + program->player_nstep.y
		* program->moves->move_speed;
	update_player_position(program, next_x, next_y);
}

void	go_side(t_program *program)
{
	float	next_x;
	float	next_y;

	next_x = program->player_pos.x + program->camera_plane.x
		* program->moves->move_side_speed;
	next_y = program->player_pos.y + program->camera_plane.y
		* program->moves->move_side_speed;
	update_player_position(program, next_x, next_y);
}

void	update_player_position(t_program *program, float next_x, float next_y)
{
	if (program->map[(int)program->player_pos.y][(int)next_x] != '1')
		program->player_pos.x = next_x;
	if (program->map[(int)next_y][(int)program->player_pos.x] != '1')
		program->player_pos.y = next_y;
}

void	pov_rotate(t_program *program)
{
	double	old_nstep_x;
	double	old_plane_x;

	old_nstep_x = program->player_nstep.x;
	old_plane_x = program->camera_plane.x;
	program->player_nstep.x = program->player_nstep.x
		* cos(program->moves->rot_speed) - program->player_nstep.y
		* sin(program->moves->rot_speed);
	program->player_nstep.y = old_nstep_x
		* sin(program->moves->rot_speed)
		+ program->player_nstep.y
		* cos(program->moves->rot_speed);
	program->camera_plane.x = program->camera_plane.x
		* cos(program->moves->rot_speed)
		- program->camera_plane.y * sin(program->moves->rot_speed);
	program->camera_plane.y = old_plane_x
		* sin(program->moves->rot_speed)
		+ program->camera_plane.y * cos(program->moves->rot_speed);
}
