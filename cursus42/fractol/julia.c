/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <ccioabnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 14:49:09 by cciobanu          #+#    #+#             */
/*   Updated: 2017/05/18 19:41:08 by ccioabnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_julia(t_win *f)
{
	f->type = J;
	f->min_re = -1.0;
	f->max_re = 2.0;
	f->min_im = -1.2;
	f->max_im = f->min_im + (f->max_re - f->min_re) * f->img.h / f->img.w;
	f->col = 0x000010;
	f->j_i = 0.1889;
	f->j_r = -0.7269;
}

int		j_calculate(t_win *f, double im, double re)
{
	int		i;
	double	z_im;
	double	z_re;
	double	z_im2;
	double	z_re2;

	z_re = re;
	z_im = im;
	i = 0;
	while (i < f->iter)
	{
		z_re2 = z_re * z_re;
		z_im2 = z_im * z_im;
		if (z_re2 + z_im2 > 4)
			return (i);
		z_im = 2 * z_re * z_im + f->j_i;
		z_re = z_re2 - z_im2 + f->j_r;
		i++;
	}
	if (i == f->iter)
		return (0);
	return (i);
}

void	julia(t_win *f)
{
	int		color;
	double	c_re;
	double	c_im;

	f->re_fact = (f->max_re - f->min_re) / (f->img.w);
	f->im_fact = (f->max_im - f->min_im) / (f->img.h);
	f->y = 0;
	while (f->y <= f->img.h)
	{
		c_im = f->max_im - f->y * f->im_fact;
		f->x = 0;
		while (f->x <= f->img.w)
		{
			c_re = f->min_re + f->x * f->re_fact;
			color = j_calculate(f, c_im, c_re) * f->col;
			pixel_put(f, color);
			f->x++;
		}
		f->y++;
	}
}
