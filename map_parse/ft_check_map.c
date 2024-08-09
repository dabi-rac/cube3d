/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:32:45 by dabi-rac          #+#    #+#             */
/*   Updated: 2024/08/09 12:32:48 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

//Se errore, libera la memoria e restituisce un messaggio in base all'errore
void	errors(int z)
{
	if (z == 1)
		ft_printf("Error:\nThe map must be closed.\n");
	if (z == 2)
		ft_printf("Error:\nElements missing inside the map.\n");
	if (z == 3)
		ft_printf("Error:\nUnexpected characters inside the map.\n");
	if (z == 6)
		ft_printf("Error:\nInvalid colours/textures.\n");
}

void	ft_free_alloc(t_program *program, int z, char **matrix)
{
	if (z == 1 || z == 3 || z == 6 || z == 2 || z == 4)
		free_imgs(program);
	if (z != 4 && z != 6 && z != 8)
	{
		if (program->map)
			ft_free_matrix(program->map);
	}
	if (matrix != NULL)
		ft_free_matrix(matrix);
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
	errors(z);
	exit(0);
}

// Se la mappa non ha il giusto simbolo per il giocatore
void	ft_check_player(t_program *program)
{
	int		i;
	int		j;
	int		pla;

	i = 0;
	pla = 0;
	while (program->map[i])
	{
		j = 0;
		while (program->map[i][j])
		{
			if (program->map[i][j] == 'N' || program->map[i][j] == 'S'
				|| program->map[i][j] == 'E' || program->map[i][j] == 'W')
			{
				pla++;
				set_player_pos(program, i, j);
			}
			j++;
		}
		i++;
	}
	if (pla != 1)
		ft_free_alloc(program, 2, NULL);
}

void	ft_check_map(t_program *program)
{
	ft_walls_check(program);
	ft_check_player(program);
}

void	set_player_pos(t_program *program, int i, int j)
{
	program->player_pos.y = (double) i;
	program->player_pos.x = (double) j;
	program->start_dir = program->map[i][j];
	program->map[i][j] = '0';
}
