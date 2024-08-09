/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:23:43 by dabi-rac          #+#    #+#             */
/*   Updated: 2024/08/09 12:28:50 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cube3d.h"

void	program_init(t_program *program)
{
	program->no_check = 0;
	program->so_check = 0;
	program->ea_check = 0;
	program->we_check = 0;
	program->f_check = 0;
	program->c_check = 0;
	program->main_img_check = 0;
	program->player_pos.x = 0;
	program->player_pos.y = 0;
	program->ray = ft_calloc(1, sizeof(t_ray));
	program->ray->dir = ft_calloc(1, sizeof(t_vector));
	program->ray->side_dist = ft_calloc(1, sizeof(t_vector));
	program->ray->delta_dist = ft_calloc(1, sizeof(t_vector));
	program->ray->step_x = 0;
	program->ray->step_y = 0;
	program->wall = ft_calloc(1, sizeof(t_wall));
	program->ray->hit = 0;
	program->ray->side = 0;
	program->ray->delta_dist->x = 0;
	program->ray->delta_dist->y = 0;
	program->map_height = 0;
	program->moves = ft_calloc(1, sizeof(t_move));
}

int	matrix_start(t_program *program, char *map)
{
	char	**matrix;

	matrix = ft_split(map, '\n');
	free(map);
	if (!matrix)
	{
		ft_printf("Error:\nCan't parse the .cub file.\n");
		return (EXIT_FAILURE);
	}
	else
	{
		ft_check_args(matrix, program);
		ft_check_map(program);
		ft_open_window(program);
	}
	ft_free_matrix(matrix);
	return (1);
}

int	main(int ac, char **av)
{
	t_program	program;
	char		*map;

	if (ac == 2)
	{
		program.ptr = mlx_init();
		ft_check_cub(&program, av[1]);
		program_init(&program);
		map = ft_extract_map(av[1], &program);
		matrix_start(&program, map);
		ft_free_alloc(&program, 10, NULL);
	}
	else
		ft_printf("Error\nInvalid argument count.\n");
	return (0);
}
