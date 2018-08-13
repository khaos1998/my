/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cord.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <cristian-ceban@mail.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:30:52 by cciobanu          #+#    #+#             */
/*   Updated: 2016/11/19 10:19:41 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_block		*ft_first_xy(t_block *blk, char *str)
{
	int x;
	int y;
	int index;
	int i;

	x = 0;
	y = 0;
	index = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '\n')
		{
			x++;
			y = -1;
		}
		if (str[i] == '#')
		{
			blk->x[index] = x;
			blk->y[index] = y;
			index++;
		}
		y++;
	}
	return (blk);
}

t_block		*ft_sec_xy(t_block *blk)
{
	int i;
	int m1;
	int m2;

	m1 = blk->x[0];
	m2 = blk->y[0];
	i = 0;
	while (i < 4)
	{
		blk->x[i] = blk->x[i] - m1;
		blk->y[i] = blk->y[i] - m2;
		i++;
	}
	return (blk);
}

t_block		*ft_xy(t_block *block)
{
	t_block	*tmp;

	tmp = block;
	while (block->next)
	{
		block = ft_first_xy(block, block->tetri);
		block = ft_sec_xy(block);
		free(block->tetri);
		block = block->next;
	}
	return (tmp);
}
