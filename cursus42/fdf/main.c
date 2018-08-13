/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <ccioabnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 17:54:00 by cciobanu          #+#    #+#             */
/*   Updated: 2017/11/24 18:40:45 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_win fdf;

	if (argc != 2)
	{
		ft_putstr("ARGC error");
		exit(1);
	}
	else
	{
		fdf.path = argv[1];
		fdf_import(&fdf);
	}
	return (0);
}

void	fdf_import(t_win *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIN_W, WIN_H, TITLE);
	fdf->map_w = 0;
	fdf->max = 0;
	fdf->map = fdf_read(fdf);
	fdf->angle = 3;
	fdf->zoom = 15;
	fdf->z_inc = 5;
	fdf->info = ON;
	fdf->lr = 0;
	fdf->ud = 0;
	fdf->axis = Z_AXIS;
	fdf_draw(fdf);
	mlx_key_hook(fdf->win, key_hook, fdf);
	mlx_loop(fdf->mlx);
}

void	fdf_redraw(t_win *fdf)
{
	mlx_clear_window(fdf->mlx, fdf->win);
	expose_hook(fdf);
}

void	fdf_reset(t_win *fdf)
{
	fdf->angle = 3;
	fdf->zoom = 15;
	fdf->z_inc = 5;
	fdf->info = ON;
	fdf->lr = 0;
	fdf->ud = 0;
	fdf->axis = Z_AXIS;
}
