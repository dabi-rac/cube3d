/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 09:42:38 by sgasperi          #+#    #+#             */
/*   Updated: 2024/08/09 12:28:43 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix[i]);
	free(matrix);
}

void	ft_free_misc(t_program *program)
{
	if (program->floor != NULL)
		free(program->floor);
	if (program->ceiling != NULL)
		free(program->ceiling);
	if (program->ray->dir != NULL)
		free(program->ray->dir);
	if (program->ray->side_dist != NULL)
		free(program->ray->side_dist);
	if (program->ray->delta_dist != NULL)
		free(program->ray->delta_dist);
	if (program->wall != NULL)
		free(program->wall);
	if (program->moves != NULL)
		free(program->moves);
	if (program->ray != NULL)
		free(program->ray);
	if (program->ptr != NULL)
		free(program->ptr);
}

void	coords_check(t_program *program, char *coord)
{
	if (!ft_strncmp(coord, "NO", 2))
		program->no_check += 1;
	if (!ft_strncmp(coord, "SO", 2))
		program->so_check += 1;
	if (!ft_strncmp(coord, "EA", 2))
		program->ea_check += 1;
	if (!ft_strncmp(coord, "WE", 2))
		program->we_check += 1;
}

void	ft_free_esc(t_program *program)
{
	free(program->ray->dir);
	free(program->ray->side_dist);
	free(program->ray->delta_dist);
	free(program->ray);
	if (program->c_check != 0)
		free(program->ceiling);
	if (program->f_check != 0)
		free(program->floor);
	free(program->wall);
	free(program->moves);
	mlx_destroy_display(program->ptr);
	free(program->ptr);
}

void	free_imgs(t_program *program)
{
	if (program->no_check != 0)
	{
		mlx_destroy_image(program->ptr, program->north_wall->image);
		free(program->north_wall);
	}
	if (program->so_check != 0)
	{
		mlx_destroy_image(program->ptr, program->south_wall->image);
		free(program->south_wall);
	}
	if (program->ea_check != 0)
	{
		mlx_destroy_image(program->ptr, program->east_wall->image);
		free(program->east_wall);
	}
	if (program->we_check != 0)
	{
		mlx_destroy_image(program->ptr, program->west_wall->image);
		free(program->west_wall);
	}
	if (program->main_img_check != 0)
	{
		mlx_destroy_image(program->ptr, program->image->image);
		free(program->image);
	}
}
