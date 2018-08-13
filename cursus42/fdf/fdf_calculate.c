/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_calculate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <ccioabnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 17:53:47 by cciobanu          #+#    #+#             */
/*   Updated: 2018/01/19 18:21:27 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	make_point(t_win *fdf, int i2, int j2)
{
	t_rot *r;

	r = malloc(sizeof(t_rot));
	if (fdf->max > 200)
		fdf->zoom = 1;
	r->x0 = fdf->map[i2][j2].d3x * fdf->zoom;
	r->y0 = fdf->map[i2][j2].d3y * fdf->zoom;
	r->z0 = fdf->map[i2][j2].d3z * fdf->z_inc;
	if (fdf->axis == X_AXIS)
		rotate_x(fdf, r);
	if (fdf->axis == Y_AXIS)
		rotate_y(fdf, r);
	if (fdf->axis == Z_AXIS)
		rotate_z(fdf, r);
	fdf->map[i2][j2].d2x = r->x - r->y + WIN_W * 0.5;
	fdf->map[i2][j2].d2y = -r->z - (r->x + r->y) * 0.5 + WIN_H * 0.3;
}

void	rotate_x(t_win *fdf, t_rot *r)
{
	r->x = r->x0;
	r->y = r->y0 * cos(fdf->angle) - r->z0 * sin(fdf->angle);
	r->z = r->y0 * sin(fdf->angle) + r->z0 * cos(fdf->angle);
}

void	rotate_y(t_win *fdf, t_rot *r)
{
	r->x = r->z0 * sin(fdf->angle) + r->x0 * cos(fdf->angle);
	r->y = r->y0;
	r->z = r->z0 * cos(fdf->angle) - r->x0 * sin(fdf->angle);
}

void	rotate_z(t_win *fdf, t_rot *r)
{
	r->x = r->x0 * cos(fdf->angle) - r->y0 * sin(fdf->angle);
	r->y = r->x0 * sin(fdf->angle) + r->y0 * cos(fdf->angle);
	r->z = r->z0;
}

void	calculate_points(t_win *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->map_h)
	{
		j = 0;
		while (j < fdf->map_w)
		{
			make_point(fdf, i, j);
			j++;
		}
		i++;
	}
}
