/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <ccioabnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 16:38:34 by cciobanu          #+#    #+#             */
/*   Updated: 2018/01/19 18:21:58 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include <sys/types.h>
# include <stdio.h>
# include <math.h>

# define WIN_W 1900
# define WIN_H 1200
# define TITLE "FDF_42"
# define BLUE 0x0041FF
# define BROWN 0xAD4F09
# define GREEN 0x25FF50
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# define X_AXIS 0
# define Y_AXIS 1
# define Z_AXIS 2
# define ON 1
# define OFF 0
# define STR_W 1700

typedef	struct	s_point
{
	int d3x;
	int d3y;
	int d3z;
	int d2x;
	int d2y;
}				t_point;

typedef	struct	s_win
{
	void	*mlx;
	void	*win;
	t_point	**map;
	char	*path;
	int		map_h;
	int		map_w;
	float	angle;
	int		zoom;
	int		lr;
	int		ud;
	int		axis;
	int		max;
	int		z_inc;
	int		info;
}				t_win;

typedef	struct	s_bh
{
	int		error;
	int		deltax;
	int		deltay;
	int		signx;
	int		signy;
}				t_bh;

typedef struct	s_rot
{
	float x0;
	float y0;
	float z0;
	float x;
	float y;
	float z;
}				t_rot;

t_point			**fdf_read(t_win *fdf);
int				ft_len(char *path);
t_point			*fdf_create_line(char *temp, int i, t_win *fdf);
int				fdf_map_w(char **line);
t_point			fdf_point(int x, int y, int z);
void			fdf_import(t_win *fdf);
int				key_hook(int key_code, t_win *fdf);
t_bh			*bh_init(t_point *p0, t_point *p1);
void			make_point(t_win *fdf, int i, int j);
void			fdf_draw(t_win *fdf);
void			calculate_points(t_win *fdf);
int				expose_hook(t_win *fdf);
void			fdf_redraw(t_win *fdf);
void			fdf_draw_line(t_win *fdf, t_point *p1, t_point *p2);
int				fdf_color(t_win *fdf, t_point *p1, t_point *p2);
void			rotate_x(t_win *fdf, t_rot *r);
void			rotate_y(t_win *fdf, t_rot *r);
void			rotate_z(t_win *fdf, t_rot *r);
void			fdf_show_info(t_win *fdf);
int				key_hook(int keycode, t_win *fdf);
void			key_hook2(int keycode, t_win *fdf);
void			key_hook3(int keycode, t_win *fdf);
void			key_hook4(int keycode, t_win *fdf);
void			fdf_reset(t_win *fdf);
#endif
