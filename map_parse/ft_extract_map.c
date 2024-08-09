/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:33:12 by dabi-rac          #+#    #+#             */
/*   Updated: 2024/08/09 12:33:14 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

char	*ft_extract_map(char *av, t_program *program)
{
	char	*new_mem;
	char	*tmp;
	char	*tmp2;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error\nThe map doesn't exist"), exit(-1), NULL);
	new_mem = ft_calloc(1, 1);
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		tmp2 = new_mem;
		new_mem = ft_strjoin(new_mem, tmp);
		free(tmp2);
		free(tmp);
		tmp = get_next_line(fd);
		program->map_height++;
	}
	free(tmp);
	return (new_mem);
}
