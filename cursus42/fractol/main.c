/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <ccioabnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 18:08:52 by cciobanu          #+#    #+#             */
/*   Updated: 2017/11/29 16:16:30 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	type_init(t_win *f, int argc, char **argv)
{
	if (argc != 2)
		f->type = -1;
	else
	{
		if (argv[1][0] == 'N')
			set_newton(f);
		else if (argv[1][0] == 'J')
			set_julia(f);
		else if (argv[1][0] == 'M')
			set_mandel(f);
		else
			f->type = -1;
	}
}

void	fract_init(t_win *f, int argc, char **argv)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, W_WIDTH, W_HEIGHT, TITLE);
	f->img.w = W_WIDTH;
	f->img.h = W_HEIGHT;
	type_init(f, argc, argv);
	f->img.img_ptr = mlx_new_image(f->mlx, f->img.w, f->img.h);
	f->img.img = mlx_get_data_addr(f->img.img_ptr, \
	&f->img.bpp, &f->img.sl, &f->img.endian);
	f->iter = 50;
	f->mouse_move = ON;
}

void	ft_error_and_info(int i)
{
	if (i == 1)
	{
		ft_putendl("Ivalid fractal name, enter");
		ft_putendl("N for Newton");
		ft_putendl("M for Mandelbrout");
		ft_putendl("J for Julia");
		exit(1);
	}
	if (i == 2)
	{
		ft_putendl("R,G,B,E,F,V for change color");
		ft_putendl("+ - for change number of iterations");
		ft_putendl("mouse button 4 and 5 for zoom and dezoom");
		ft_putendl("O for stop mouse move in Julia");
		ft_putendl("Arrows to navigate");
	}
}

int		expose_hook(t_win *f)
{
	if (f->type == J)
		julia(f);
	if (f->type == M)
		mandel(f);
	if (f->type == N)
		newton(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img.img_ptr, 0, 0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_win fract;

	fract_init(&fract, argc, argv);
	if (fract.type == -1)
		ft_error_and_info(1);
	mlx_key_hook(fract.win, key_hook, &fract);
	mlx_mouse_hook(fract.win, mouse_hook, &fract);
	mlx_hook(fract.win, 6, 1L << 6, mouse_move, &fract);
	mlx_expose_hook(fract.win, expose_hook, &fract);
	mlx_loop(fract.mlx);
	return (0);
}
