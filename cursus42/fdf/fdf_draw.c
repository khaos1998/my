/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <ccioabnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 18:50:02 by cciobanu          #+#    #+#             */
/*   Updated: 2017/11/24 18:41:39 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_bh	*bh_init(t_point *p1, t_point *p2)
{
	t_bh *bh;

	bh = malloc(sizeof(t_bh));
	bh->deltax = abs(p2->d2x - p1->d2x);
	bh->deltay = abs(p2->d2y - p1->d2y);
	bh->signx = p1->d2x < p2->d2x ? 1 : -1;
	bh->signy = p1->d2y < p2->d2y ? 1 : -1;
	bh->error = (bh->deltax > bh->deltay ? bh->deltax : -(bh->deltay)) / 2;
	return (bh);
}

void	fdf_draw_line(t_win *fdf, t_point *p1, t_point *p2)
{
	t_bh	*bres;
	int		error2;
	int		x;
	int		y;

	bres = bh_init(p1, p2);
	x = p1->d2x;
	y = p1->d2y;
	mlx_pixel_put(fdf->mlx, fdf->win, p2->d2x + fdf->lr,
			p2->d2y + fdf->ud, fdf_color(fdf, p1, p2));
	while ((x != p2->d2x) || (y != p2->d2y))
	{
		mlx_pixel_put(fdf->mlx, fdf->win, x + fdf->lr, y + fdf->ud,
				fdf_color(fdf, p1, p2));
		if ((error2 = bres->error) > (-bres->deltax))
		{
			bres->error = bres->error - bres->deltay;
			x = x + bres->signx;
		}
		if (error2 < bres->deltay)
		{
			bres->error = bres->error + bres->deltax;
			y = y + bres->signy;
		}
	}
}

void	fdf_draw(t_win *fdf)
{
	int	i;
	int	j;

	i = 0;
	calculate_points(fdf);
	while (i < fdf->map_h)
	{
		j = 0;
		while (j < fdf->map_w)
		{
			if (j < fdf->map_w - 1)
				fdf_draw_line(fdf, &(fdf->map[i][j]), &(fdf->map[i][j + 1]));
			if (i < fdf->map_h - 1)
				fdf_draw_line(fdf, &(fdf->map[i][j]), &(fdf->map[i + 1][j]));
			j++;
		}
		i++;
	}
	if (fdf->info == ON)
		fdf_show_info(fdf);
}

int		fdf_color(t_win *fdf, t_point *p1, t_point *p2)
{
	int temp;

	temp = (p1->d3z + p2->d3z) / 2;
	if (temp < 0)
		return (BLUE);
	if (temp == 0)
		return (GREEN);
	if (temp > (fdf->max * 0.8))
		return (WHITE);
	return (BROWN);
}

void	fdf_show_info(t_win *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, STR_W, 20, BLUE, "LEGEND");
	mlx_string_put(fdf->mlx, fdf->win, STR_W, 35, BLUE, "Sale: q/e");
	mlx_string_put(fdf->mlx, fdf->win, STR_W, 50, BLUE, "Translation: arrow");
	mlx_string_put(fdf->mlx, fdf->win, STR_W, 65, BLUE, "Zoom: -/+");
	mlx_string_put(fdf->mlx, fdf->win, STR_W, 80, BLUE, "Change axis: 1/2/3");
	mlx_string_put(fdf->mlx, fdf->win, STR_W, 95, BLUE, "Rotation: a/d");
	mlx_string_put(fdf->mlx, fdf->win, STR_W, 110, BLUE, "Legend on/off: o");
	mlx_string_put(fdf->mlx, fdf->win, STR_W, 125, BLUE, "EXIT: ESC");
	mlx_string_put(fdf->mlx, fdf->win, STR_W, 140, BLUE, "RESET: r");
}
