/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:32:38 by dabi-rac          #+#    #+#             */
/*   Updated: 2024/08/09 12:32:39 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_check_map_file(char *map, t_program *program)
{
	char	**map_matrix;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map_matrix = ft_split(map, '\n');
	ft_check_args(map_matrix, program);
	while (map_matrix[i])
	{
		if (map_matrix[i][0] == '1')
		{
			program->map[j] = map_matrix[i];
			i++;
		}
	}
}
