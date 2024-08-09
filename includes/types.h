/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:17:37 by sgasperi          #+#    #+#             */
/*   Updated: 2024/08/09 12:26:54 by dabi-rac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

//struct
typedef enum s_bool
{
	TRUE=1,
	FALSE=0,
}	t_bool;

typedef struct s_image
{
	void	*image;
	char	*img_ptr;
	int		line_len;
	int		bpx;
	int		endian;
}	t_image;

typedef struct s_colour
{
	int	r;
	int	g;
	int	b;
	int	hex;
}	t_colour;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_ray
{
	t_vector	*dir;
	t_vector	*side_dist;
	t_vector	*delta_dist;
	int			step_x;
	int			step_y;
	int			map_x;
	int			map_y;
	double		perp_wall_dist;
	int			side;
	int			hit;
	int			line_height;
	int			draw_start;
	int			draw_end;
}	t_ray;

typedef struct s_wall
{
	double	wall_x;
	int		tex_x;
	int		tex_y;
	int		tex_num;
	double	step;
	double	tex_pos;

}	t_wall;

typedef struct s_move
{
	int		w;
	int		a;
	int		s;
	int		d;
	int		l;
	int		r;
	double	move_speed;
	double	move_side_speed;
	double	rot_speed;
}	t_move;

typedef struct s_program
{
	t_ray		*ray;
	void		*ptr;
	void		*window;
	char		**map;
	char		start_dir;
	t_vector	player_pos;
	t_vector	player_nstep;
	t_vector	camera_plane;
	t_image		*image;
	t_image		*north_wall;
	t_image		*south_wall;
	t_image		*west_wall;
	t_image		*east_wall;
	t_colour	*floor;
	t_colour	*ceiling;
	double		camera_x;
	int			map_height;
	int			map_width;
	int			tstamp;
	int			loop;
	int			img_size;
	int			end_result;
	int			no_check;
	int			so_check;
	int			ea_check;
	int			we_check;
	int			f_check;
	int			c_check;
	int			main_img_check;
	t_wall		*wall;
	t_move		*moves;
}	t_program;

#endif
