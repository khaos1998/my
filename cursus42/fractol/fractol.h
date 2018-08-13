/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <ccioabnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 18:00:23 by cciobanu          #+#    #+#             */
/*   Updated: 2017/11/29 16:17:38 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include <sys/types.h>
# include <math.h>
# include <stdio.h>

# define W_WIDTH 800
# define W_HEIGHT 800
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ON 1
# define OFF -1
# define R 15
# define G 5
# define B 11
# define Z 122
# define O 31
# define X 7
# define E 14
# define F 3
# define V 9
# define A 0
# define S 1
# define I 34
# define PLUS 24
# define MINUS 27
# define TITLE "FRACTOL"
# define J 0
# define M 1
# define N 2
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define BLUE 0x0000FF
# define GREEN 0x00FF00
# define YELLOW 0xFFF00

typedef struct	s_img
{
	void		*img_ptr;
	char		*img;
	int			bpp;
	int			sl;
	int			endian;
	int			w;
	int			h;

}				t_img;

typedef struct	s_win
{
	void		*mlx;
	void		*win;
	int			type;
	t_img		img;
	int			x;
	int			y;
	int			iter;
	double		min_re;
	double		max_re;
	double		min_im;
	double		max_im;
	double		re_fact;
	double		im_fact;
	int			temp;
	int			col;
	double		j_i;
	double		j_r;
	int			mouse_move;
	double		xs;

}				t_win;

void			fract_init(t_win *f, int argc, char **argv);
void			ft_error_and_info(int i);
int				key_hook(int key_code, t_win *f);
void			julia(t_win *f);
int				j_calculate(t_win *f, double x0, double y0);
int				m_calculate(t_win *f, double im, double re);
void			set_mandel(t_win *f);
void			mandel(t_win *f);
void			set_julia(t_win *f);
void			set_newton(t_win *f);
int				expose_hook(t_win *f);
void			pixel_put(t_win *f, int color);
int				mouse_hook(int button, int x, int y, t_win *f);
int				mouse_move(int x, int y, t_win *f);
int				n_calculate(t_win *f, double x0, double y0);
void			set_newton(t_win *f);
void			newton(t_win *f);
void			key_hook2(int key_code, t_win *f);
#endif
