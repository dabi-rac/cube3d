/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:33:05 by dabi-rac          #+#    #+#             */
/*   Updated: 2024/08/09 12:33:06 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_clear_map(char **map, t_program *program, int posMap)
{
	int	j;
	int	len;

	j = 0;
	program->map = malloc((program->map_height + 1) * sizeof(char *));
	if (!program->map)
		return ;
	while (map[posMap] && j < program->map_height)
	{
		len = ft_strlen(map[posMap]);
		program->map[j] = malloc((len + 1) * sizeof(char));
		if (!program->map[j])
		{
			while (--j >= 0)
				free(program->map[j]);
			free(program->map);
			program->map = NULL;
			return ;
		}
		ft_strlcpy(program->map[j], map[posMap], len + 1);
		posMap++;
		j++;
	}
	program->map[j] = NULL;
	ft_free_matrix(map);
}
