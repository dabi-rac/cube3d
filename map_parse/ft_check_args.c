/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:32:26 by dabi-rac          #+#    #+#             */
/*   Updated: 2024/08/09 12:32:28 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_check_floor(char **av, int i, t_program *program)
{
	int		*rgb;

	rgb = color_splitting(av, i, program);
	if (rgb)
	{
		if (program->f_check == 0)
			program->floor = ft_calloc(1, sizeof(t_colour));
		color_parse(program, rgb, 'F');
		free(rgb);
		program->floor->hex = ft_rgb_to_hex(program->floor->r,
				program->floor->g, program->floor->b);
		if ((program->floor->r == -1) || (program->floor->g == -1)
			|| program->floor->b == -1)
		{
			free(program->floor);
			ft_free_alloc(program, 6, av);
		}
		program->f_check += 1;
	}
	else
	{
		free(rgb);
		ft_free_alloc(program, 6, av);
	}
}

void	ft_check_ceiling(char **av, int i, t_program *program)
{
	int		*rgb;

	rgb = color_splitting(av, i, program);
	if (rgb)
	{
		if (program->c_check == 0)
			program->ceiling = ft_calloc(1, sizeof(t_colour));
		color_parse(program, rgb, 'C');
		free(rgb);
		program->ceiling->hex = ft_rgb_to_hex(program->ceiling->r,
				program->ceiling->g, program->ceiling->b);
		if (program->ceiling->r == -1 || program->ceiling->g == -1
			|| program->ceiling->b == -1)
		{
			free(program->ceiling);
			ft_free_alloc(program, 6, av);
		}
		program->c_check += 1;
	}
	else
	{
		free(rgb);
		ft_free_alloc(program, 6, NULL);
	}
}

void	check_textures(char **av, int i, t_program *program)
{
	char	**tmp;

	tmp = ft_split(av[i], ' ');
	if (ft_strlen(tmp[0]) == 2)
	{
		check_north(program, tmp, av);
		check_south(program, tmp, av);
		check_east(program, tmp, av);
		check_west(program, tmp, av);
	}
	if (tmp != NULL)
		ft_free_matrix(tmp);
}

void	ft_check_args(char **av, t_program *program)
{
	int		i;

	i = 0;
	while (i < 6)
	{
		if (ft_matrix_len(av) <= i)
		{
			ft_printf("Error:\nIn check args, invalid matrix length.\n");
			break ;
		}
		if (ft_strncmp(av[i], "F", 1) == 0 && program->f_check == 0)
			ft_check_floor(av, i, program);
		if (ft_strncmp(av[i], "C", 1) == 0 && program->c_check == 0)
			ft_check_ceiling(av, i, program);
		check_textures(av, i, program);
		i++;
	}
	if (program->no_check != 1 || program->so_check != 1
		|| program->ea_check != 1 || program->we_check != 1
		|| program->f_check != 1 || program->c_check != 1)
	{
		ft_free_alloc(program, 6, av);
	}
	ft_clear_map(av, program, i);
}
