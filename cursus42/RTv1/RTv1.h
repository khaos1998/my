/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 11:28:06 by cciobanu          #+#    #+#             */
/*   Updated: 2017/06/22 11:28:09 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTv1_H

# define RTv1_H

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include <sys/types.h>
# include <math.h>
# include <stdio.h>

# define TITLE RTv1

typedef struct 	s_xyz
{
	float x;
	float y;
	float z;
}				t_xyz;

typedef struct 	s_img
{
	void		*img_ptr;
	char		*img;
	int			bpp;
	int			sl;
	int			endian;
	int			w;
	int			h;
}				t_img;

typedef struct 	s_win
{
	void 	*mlx;
	void 	*win;
	t_img 	img;
	int 	x;
	int 	y;
}				t_win;

#endif