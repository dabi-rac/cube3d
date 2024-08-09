/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:13:02 by sgasperi          #+#    #+#             */
/*   Updated: 2024/08/09 12:28:45 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	ft_matrix_len(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
		i++;
	return (i);
}

char	**split_matrix(t_program *program, char	*av)
{
	char	**colour_matrix;
	char	**colour_matrix1;

	colour_matrix1 = ft_split(av, ' ');
	if (!colour_matrix1)
		ft_free_alloc(program, 6, &av);
	if (ft_matrix_len(colour_matrix1) != 2)
	{
		ft_free_matrix(colour_matrix1);
		return (NULL);
	}
	colour_matrix = ft_split(colour_matrix1[1], ',');
	if (!colour_matrix)
	{
		return (NULL);
	}
	ft_free_matrix(colour_matrix1);
	return (colour_matrix);
}

//Se la mappa non é un .cub
void	ft_check_cub(t_program *program, char *av)
{
	int		l;

	l = ft_strlen(av);
	if (!(av[l - 1] == 'b' && av[l - 2] == 'u' && av[l - 3] == 'c'
			&& av[l - 4] == '.'))
	{
		ft_printf("Errore: la mappa deve essere in formato .cub\n");
		mlx_destroy_display(program->ptr);
		free(program->ptr);
		exit(0);
	}
}

// int	*color_splitting(char **av, int i, t_program *program)
// {
// 	char	**colour_matrix;
// 	int *rgb;

// 	rgb = (int *)malloc(3 * sizeof(int));
// 	if (rgb != NULL) {
// 		rgb[0] = 0;
// 		rgb[1] = 0;
// 		rgb[2] = 0;
// 	}
// 	colour_matrix = split_matrix(program, av[i]);
// 	if (ft_matrix_len(colour_matrix) == 3
// 		&& (int)ft_strlen(colour_matrix[0]) <= 3
// 		&& (int)ft_strlen(colour_matrix[1]) <= 3
// 		&& (int)ft_strlen(colour_matrix[2]) <= 3)
// 	{
// 		rgb = {ft_atoi(colour_matrix[0]), ft_atoi(colour_matrix[1]),
// 			ft_atoi(colour_matrix[2])};
// 		ft_free_matrix(colour_matrix);
// 	}
// 	else
// 	{
// 		rgb[0] = -1;
// 		rgb[1] = -1;
// 		rgb[2] = -1;
// 	}
// 	return (rgb);
// }
int	colour_arguments(char **colour_matrix)
{
	if (ft_matrix_len(colour_matrix) == 3
		&& (int)ft_strlen(colour_matrix[0]) <= 3
		&& (int)ft_strlen(colour_matrix[1]) <= 3
		&& (int)ft_strlen(colour_matrix[2]) <= 3)
		return (1);
	return (0);
}

int	*color_splitting(char **av, int i, t_program *program)
{
	char	**colour_matrix;
	int		*rgb;

	colour_matrix = split_matrix(program, av[i]);
	if (colour_matrix == NULL)
		ft_free_alloc(program, 6, av);
	if (colour_arguments(colour_matrix))
	{
		rgb = (int *)malloc(3 * sizeof(int));
		rgb[0] = ft_atoi(colour_matrix[0]);
		rgb[1] = ft_atoi(colour_matrix[1]);
		rgb[2] = ft_atoi(colour_matrix[2]);
		ft_free_matrix(colour_matrix);
		return (rgb);
	}
	else
	{
		ft_free_matrix(colour_matrix);
		return (NULL);
	}
}
