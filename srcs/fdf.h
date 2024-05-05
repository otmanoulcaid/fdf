/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulcaid <ooulcaid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:56:50 by ooulcaid          #+#    #+#             */
/*   Updated: 2024/03/05 10:31:12 by ooulcaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "../utils/utils.h"
# include "stdio.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>

/*------helpful macros------*/

# define MAX_WIDTH 1800
# define MAX_HEIGH 1000
# define MENU_WIDTH 150

typedef enum e_keys
{
	ZOOM_OUT	= 0,
	ZOOM_IN		= 6,
	CANCEL		= 17,
	INIT		= 49,
	QUIT		= 53,
	ROT_X_DOWN	= 84,
	ROT_Y_L		= 86,
	ROT_Y_R		= 88,
	ROT_X_UP	= 91,
	ROT_Z_R		= 85,
	ROT_Z_L		= 92,
	PROJECT		= 83,
	ALT_DOWN	= 82,
	ALT_UP		= 87,
	MOVE_LEFT	= 123,
	MOVE_RIGHT	= 124,
	MOVE_DOWN	= 125,
	MOVE_UP		= 126,
}	t_keys;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_map
{
	int		width;
	int		height;
	int		bbp;
	int		endian;
	int		win_x;
	void	*img;
	void	*c_panel;
	char	*img_addr;
	t_point	**cord;
}	t_map;

typedef struct s_fdf
{
	int		z_scale;
	int		x_scale;
	int		y_scale;
	double	alpha;
	double	beta;
	double	gama;
	int		zoom;
	int		is_iso;
	int		fd;
	void	*mlx;
	void	*win_ptr;
	t_map	*map;
}	t_fdf;

/*-----------error----------*/
void	faillure(char **str);
void	ft_throw(char *strerr);

/*--------bool-------*/
int		valid_extention(char *av);
int		ternary(int boolean, int a, int b);
int		in_hexa(char *str);

/*--------getters--------*/

int		get_zoom(t_fdf *data);

/*------------fdf----------*/
void	parse_map(t_fdf *fdf, char *av);
void	my_mlx_pixel_put(t_fdf *data, t_point *x);
void	init_mlx_content(t_fdf *data);
void	init_fdf(t_fdf *data, int height);
void	fdf(t_fdf *data);
void	bresenham(t_point p1, t_point p2, t_fdf *data);
void	set_coordinate(t_point *p1, t_point *p2, t_fdf *data);
int		event_handling(int key, t_fdf *data);
void	finish(t_fdf *data);

#endif