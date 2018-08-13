/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manndel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <ccioabnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 20:48:39 by cciobanu          #+#    #+#             */
/*   Updated: 2017/11/29 16:19:39 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_mandel(t_win *f)
{
	f->type = M;
	f->min_re = -2;
	f->max_re = 2;
	f->min_im = -2;
	f->max_im = f->min_im + (f->max_re - f->min_re) * f->img.h / f->img.w;
	f->col = 0x000010;
}

int		m_calculate(t_win *f, double im, double re)
{
	int		i;
	double	z_im;
	double	z_re;
	double	z_im2;
	double	z_re2;

	z_re = 0;
	z_im = 0;
	i = 0;
	while (i < f->iter)
	{
		z_re2 = z_re * z_re;
		z_im2 = z_im * z_im;
		if (z_re2 + z_im2 > 4)
			return (i);
		z_im = 2 * z_re * z_im + im;
		z_re = z_re2 - z_im2 + re;
		i++;
	}
	if (i == f->iter)
		return (0);
	return (i);
}

void	mandel(t_win *f)
{
	double	c_re;
	double	c_im;
	int		color;

	f->re_fact = (f->max_re - f->min_re) / (f->img.w - 1);
	f->im_fact = (f->max_im - f->min_im) / (f->img.h - 1);
	f->y = 0;
	while (f->y <= f->img.h)
	{
		c_im = f->max_im - f->y * f->im_fact;
		f->x = 0;
		while (f->x <= f->img.w)
		{
			c_re = f->min_re + f->x * f->re_fact;
			color = (f->col * m_calculate(f, c_im, c_re));
			pixel_put(f, color);
			f->x++;
		}
		f->y++;
	}
}
