/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <ccioabnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 18:38:52 by cciobanu          #+#    #+#             */
/*   Updated: 2017/05/28 10:53:08 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_win *fdf)
{
	fdf_draw(fdf);
	return (0);
}

int		key_hook(int keycode, t_win *fdf)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 0)
	{
		fdf->angle += 0.05;
		fdf_redraw(fdf);
	}
	if (keycode == 2)
	{
		fdf->angle -= 0.05;
		fdf_redraw(fdf);
	}
	if (keycode == 24)
	{
		fdf->zoom++;
		fdf_redraw(fdf);
	}
	if (keycode == 27)
	{
		fdf->zoom--;
		fdf_redraw(fdf);
	}
	key_hook2(keycode, fdf);
	return (0);
}

void	key_hook2(int keycode, t_win *fdf)
{
	if (keycode == 126)
	{
		fdf->ud -= 10;
		fdf_redraw(fdf);
	}
	if (keycode == 125)
	{
		fdf->ud += 10;
		fdf_redraw(fdf);
	}
	if (keycode == 124)
	{
		fdf->lr += 10;
		fdf_redraw(fdf);
	}
	if (keycode == 123)
	{
		fdf->lr -= 10;
		fdf_redraw(fdf);
	}
	key_hook3(keycode, fdf);
}

void	key_hook3(int keycode, t_win *fdf)
{
	if (keycode == 18)
	{
		fdf->axis = X_AXIS;
		fdf_redraw(fdf);
	}
	if (keycode == 19)
	{
		fdf->axis = Y_AXIS;
		fdf_redraw(fdf);
	}
	if (keycode == 20)
	{
		fdf->axis = Z_AXIS;
		fdf_redraw(fdf);
	}
	if (keycode == 12)
	{
		fdf->z_inc--;
		fdf_redraw(fdf);
	}
	key_hook4(keycode, fdf);
}

void	key_hook4(int keycode, t_win *fdf)
{
	if (keycode == 14)
	{
		fdf->z_inc++;
		fdf_redraw(fdf);
	}
	if (keycode == 31)
	{
		if (fdf->info == ON)
			fdf->info = OFF;
		else
			fdf->info = ON;
		fdf_redraw(fdf);
	}
	if (keycode == 15)
	{
		fdf_reset(fdf);
		fdf_redraw(fdf);
	}
}
