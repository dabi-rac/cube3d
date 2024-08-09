/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:32:55 by dabi-rac          #+#    #+#             */
/*   Updated: 2024/08/09 12:32:57 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	check_north(t_program *program, char **tmp, char **av)
{
	if (!ft_strncmp(tmp[0], "NO", 2))
	{
		if (program->no_check == 0 && tmp[1])
		{
			program->north_wall = ft_calloc(1, sizeof(t_image));
			if (check_tex_coords(program, program->north_wall, tmp))
				program->no_check += 1;
			else
			{
				ft_free_matrix(av);
				free(program->north_wall);
				program->no_check = 0;
				ft_free_alloc(program, 6, tmp);
			}
		}
	}
}

void	check_south(t_program *program, char **tmp, char **av)
{
	if (!ft_strncmp(tmp[0], "SO", 2))
	{
		if (program->so_check == 0 && tmp[1])
		{
			program->south_wall = ft_calloc(1, sizeof(t_image));
			if (check_tex_coords(program, program->south_wall, tmp))
				program->so_check += 1;
			else
			{
				ft_free_matrix(av);
				free(program->south_wall);
				program->so_check = 0;
				ft_free_alloc(program, 6, tmp);
			}
		}
	}
}

void	check_east(t_program *program, char **tmp, char **av)
{
	if (!ft_strncmp(tmp[0], "EA", 2))
	{
		if (program->ea_check == 0 && tmp[1])
		{
			program->east_wall = ft_calloc(1, sizeof(t_image));
			if (check_tex_coords(program, program->east_wall, tmp))
				program->ea_check += 1;
			else
			{
				ft_free_matrix(av);
				free(program->east_wall);
				program->ea_check = 0;
				ft_free_alloc(program, 6, tmp);
			}
		}
	}
}

void	check_west(t_program *program, char **tmp, char **av)
{
	if (!ft_strncmp(tmp[0], "WE", 2))
	{
		if (program->we_check == 0 && tmp[1])
		{
			program->west_wall = ft_calloc(1, sizeof(t_image));
			if (check_tex_coords(program, program->west_wall, tmp))
				program->we_check += 1;
			else
			{
				ft_free_matrix(av);
				free(program->west_wall);
				program->we_check = 0;
				ft_free_alloc(program, 6, tmp);
			}
		}
	}
}
