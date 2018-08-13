/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 10:49:11 by cciobanu          #+#    #+#             */
/*   Updated: 2017/05/27 11:53:19 by ccioabnu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_newton(t_win *f)
{
	f->type = N;
	f->min_re = -4;
	f->max_re = 4;
	f->min_im = -4;
	f->max_im = f->min_im + (f->max_re - f->min_re) * f->img.h / f->img.w;
	f->col = 0x000010;
	f->xs = f->img.w / 2;
}

int		n_calculate(t_win *f, double re, double im)
{
	int		i;
	int		i2;
	double	im2;
	double	re2;

	i = 0;
	i2 = 0;
	while (i < f->iter)
	{
		re2 = 2 * re / 3 - (re * re - im * im) \
		/ (3 * (re * re + im * im) * (re * re + im * im));
		im2 = 2 * im / 3 + (2 * re * im) \
		/ (3 * (re * re + im * im) * (re * re + im * im));
		im = im2;
		re = re2;
		if (im * im + re * re < 0.5)
			i2 = i;
		i++;
	}
	return (i2);
}

void	newton(t_win *f)
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
			color = (f->col * n_calculate(f, c_im, c_re));
			pixel_put(f, color);
			f->x++;
		}
		f->y++;
	}
}
