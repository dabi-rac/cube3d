/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:15:09 by dabi-rac          #+#    #+#             */
/*   Updated: 2024/08/09 12:28:29 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	handle_move(t_program *program)
{
	mlx_hook(program->window, 17, 0, &window_close, program);
	mlx_loop_hook(program->ptr, &ft_render, program);
	mlx_hook(program->window, 2, 1L << 0, &keypress, program);
	mlx_hook(program->window, 3, 1L << 1, &keyrelease, program);
	mlx_loop(program->ptr);
}

int	window_close(t_program *program)
{
	if (program->window != NULL)
		mlx_destroy_window(program->ptr, program->window);
	free_imgs(program);
	ft_free_alloc(program, 5, NULL);
	return (0);
}

int	keypress(int keycode, t_program *program)
{
	if (keycode == 65307)
		window_close(program);
	if (keycode == KB_W || keycode == KB_UP)
	{
		program->moves->w = 1;
		program->moves->move_speed = .05;
	}
	if (keycode == KB_S || keycode == KB_DOWN)
	{
		program->moves->s = 1;
		program->moves->move_speed = -.05;
	}
	set_movement(program, keycode);
	return (1);
}

void	set_movement(t_program *program, int keycode)
{
	if (keycode == KB_LEFT)
	{
		program->moves->l = 1;
		program->moves->rot_speed = .05;
	}
	if (keycode == KB_RIGHT)
	{
		program->moves->r = 1;
		program->moves->rot_speed = -.05;
	}
	if (keycode == KB_A)
	{
		program->moves->a = 1;
		program->moves->move_side_speed = .05;
	}
	if (keycode == KB_D)
	{
		program->moves->d = 1;
		program->moves->move_side_speed = -.05;
	}
}

int	keyrelease(int keycode, t_program *program)
{
	(void)keycode;
	program->moves->w = 0;
	program->moves->a = 0;
	program->moves->s = 0;
	program->moves->d = 0;
	program->moves->l = 0;
	program->moves->r = 0;
	program->moves->move_speed = 0.0;
	program->moves->move_side_speed = 0.0;
	return (1);
}
