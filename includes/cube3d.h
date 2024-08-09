/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:26:28 by dabi-rac          #+#    #+#             */
/*   Updated: 2024/08/09 12:26:30 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H
# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define TEXWIDTH 64
# define TEXHEIGHT 64

# define KB_W 119
# define KB_A 97
# define KB_S 115
# define KB_D 100
# define KB_LEFT 65361
# define KB_RIGHT 65363
# define KB_UP 65362
# define KB_DOWN 65364

# include "types.h"
# include "enums.h"
# include "get_next_line.h"
# include "../libs/libft/libft.h"
# include "../libs/ft_printf/ft_printf.h"
# include "../mlx_linux/mlx.h"
# include <stdio.h>
# include <math.h>

void	ft_check_args(char **av, t_program *program);
void	ft_check_map_file(char *map, t_program *program);
void	ft_check_map(t_program *program);
void	ft_clear_map(char **map, t_program *program, int posMap);
char	*ft_extract_map(char *av, t_program *program);
void	ft_walls_check(t_program *program);
void	ft_free_alloc(t_program *program, int z, char **matrix);
void	ft_check_cub(t_program *program, char *av);
int		ft_check_spaces(t_program *program);
void	ft_free_matrix(char **matrix);
int		ft_matrix_len(char **matrix);
int		ft_open_window(t_program *program);
void	ft_ray_step(t_program *program, int i);
void	ft_ray_step_init(t_program *program);
void	ft_ray_dda(t_program *program);
void	ft_ray_step_calc(t_program *program);
void	ft_perp_dist(t_program *program);
void	ft_wall_color(t_program *program);
void	my_mlx_pixel_put(t_image *image, int x, int y, int color);
void	ft_load_images(t_program *program);
int		ft_rgb_to_hex(int r, int g, int b);
int		ft_render(t_program *program);
void	ft_render_wall(t_program *program);
void	ft_render_y(t_program *program, int x);
void	ft_render_floor_ceiling(t_program *program);
int		get_pixel(t_image *image, int x, int y);
void	ft_draw_wall(t_program *program, t_wall *data, int x, int y);
void	handle_move(t_program *program);
int		window_close(t_program *program);
int		keypress( int keycode, t_program *program);
void	set_movement(t_program *program, int keycode);
void	go_forward(t_program *program);
void	update_player_position(t_program *program, float next_x, float next_y);
void	go_side(t_program *program);
int		keyrelease(int keycode, t_program *program);
void	pov_rotate(t_program *program);
int		check_colors(int colour_matrix);
int		check_tex_coords(t_program *program, t_image *img,
			char **tmp);
void	ft_free_misc(t_program *program);
void	set_player_pos(t_program *program, int i, int j);
void	coords_check(t_program *program, char *coord);
char	**split_matrix(t_program *program, char	*av);
void	free_imgs(t_program *program);
void	check_north(t_program *program, char **tmp, char **av);
void	check_south(t_program *program, char **tmp, char **av);
void	check_east(t_program *program, char **tmp, char **av);
void	check_west(t_program *program, char **tmp, char **av);
int		*color_splitting(char **av, int i, t_program *program);
int		ft_array_int_len(int *array);
void	color_parse(t_program *program, int	*rgb, char c);

#endif
