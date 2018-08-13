/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <ccioabnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 10:36:26 by cciobanu          #+#    #+#             */
/*   Updated: 2017/11/29 16:18:27 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook(int key_code, t_win *f)
{
	double tmp;

	if (key_code == ESC)
	{
		exit(1);
		mlx_destroy_window(f->mlx, f->win);
	}
	if (key_code == DOWN || key_code == UP)
	{
		tmp = (f->max_im - f->min_im) / 4;
		if (key_code == DOWN)
		{
			f->min_im += tmp;
			f->max_im += tmp;
		}
		else
		{
			f->min_im -= tmp;
			f->max_im -= tmp;
		}
	}
	key_hook2(key_code, f);
	return (0);
}

void	key_hook2(int key_code, t_win *f)
{
	double tmp;

	if (key_code == LEFT || key_code == RIGHT)
	{
		tmp = (f->max_re - f->min_re) / 4;
		f->max_re += (key_code == LEFT ? tmp : -tmp);
		f->min_re += (key_code == LEFT ? tmp : -tmp);
	}
	if (key_code == R || key_code == E)
		f->col += (key_code == R ? 0x100000 : -0x100000);
	if (key_code == G || key_code == F)
		f->col += (key_code == G ? 0x001000 : -0x001000);
	if (key_code == B || key_code == V)
		f->col += (key_code == B ? 0x000010 : -0x000010);
	if (key_code == PLUS || key_code == MINUS)
		f->iter += (key_code == PLUS ? 1 : -1);
	if (key_code == I)
		ft_error_and_info(2);
	if (key_code == O)
		f->mouse_move *= -1;
	expose_hook(f);
}

int		mouse_move(int x, int y, t_win *f)
{
	if (f->type == J && f->mouse_move == ON)
	{
		f->re_fact = (f->max_re - f->min_re) / (f->img.w);
		f->im_fact = (f->max_im - f->min_im) / (f->img.h);
		f->j_i = f->max_im - y * f->im_fact;
		f->j_r = f->min_re + x * f->re_fact;
		expose_hook(f);
	}
	if (f->type == N)
		f->xs = x;
	return (0);
}

int		mouse_hook(int button, int x, int y, t_win *f)
{
	double i;
	double r;
	double w;
	double h;

	i = f->max_im - y * f->im_fact;
	r = f->min_re + x * f->re_fact;
	w = f->max_re - f->min_re;
	h = f->max_im - f->min_im;
	if (button == 5 || button == 4)
	{
		w = w * (button == 5 ? 0.7 : 1.42);
		h = h * (button == 5 ? 0.7 : 1.42);
		f->max_im = i + h / 2;
		f->min_im = i - h / 2;
		f->max_re = r + w / 2;
		f->min_re = r - w / 2;
		expose_hook(f);
	}
	return (1);
}
