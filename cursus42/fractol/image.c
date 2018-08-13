/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 11:38:00 by cciobanu          #+#    #+#             */
/*   Updated: 2017/04/30 11:57:28 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_put(t_win *f, int c)
{
	ft_memcpy(&f->img.img[(f->x * f->img.bpp / 8) + (f->y * f->img.sl)], &c, 4);
}
