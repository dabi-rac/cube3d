/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_walls_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:33:21 by dabi-rac          #+#    #+#             */
/*   Updated: 2024/08/09 12:33:21 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	ft_chrcmp(char c, t_program *program)
{
	if (c == ' ')
		c = '0';
	if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'E'
		&& c != 'W')
		ft_free_alloc(program, 3, NULL);
	(void)program;
}

void	check_first_last(t_program *program)
{
	int	j;

	j = 0;
	while (program->map[0][j])
	{
		if (program->map[0][j] != '1')
			ft_free_alloc(program, 2, NULL);
		j++;
	}
	j = 0;
	while (program->map[ft_matrix_len(program->map)][j])
	{
		if (program->map[ft_matrix_len(program->map)][j] != '1'
			&& program->map[ft_matrix_len(program->map)][j] != '\0')
		{
			ft_free_alloc(program, 3, NULL);
		}
		j++;
	}
}

void	ft_spaces_to_zero(t_program *program)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (program->map[i])
	{
		j = 0;
		while (program->map[i][j])
		{
			if (program->map[i][j] == ' ')
				program->map[i][j] = '1';
			j++;
		}
		i++;
	}
}

//Se non é chiusa/circondata da muri
void	ft_walls_check(t_program *program)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	ft_spaces_to_zero(program);
	while (program->map[i])
	{
		j = 0;
		while (program->map[i][j])
		{
			if (program->map[i][j] == '0')
			{
				if (j >= (int)ft_strlen(program->map[i + 1])
					|| j >= (int)ft_strlen(program->map[i - 1]))
					ft_free_alloc(program, 1, NULL);
				ft_chrcmp(program->map[i][j + 1], program);
				ft_chrcmp(program->map[i][j - 1], program);
				ft_chrcmp(program->map[i + 1][j], program);
				ft_chrcmp(program->map[i - 1][j], program);
			}
			j++;
		}
		i++;
	}
}
