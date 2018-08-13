/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <cristian-ceban@mail.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:03:29 by cciobanu          #+#    #+#             */
/*   Updated: 2016/11/19 13:39:56 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	g_size;

int		ft_check_position(char **tab, t_block *tetri, int pos_x, int pos_y)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if ((tetri->x[i] + pos_x >= g_size) || (tetri->x[i] + pos_x < 0))
			return (1);
		if ((tetri->y[i] + pos_y >= g_size) || (tetri->y[i] + pos_y < 0))
			return (1);
		if (tab[tetri->x[i] + pos_x][tetri->y[i] + pos_y] != '.')
			return (1);
		i++;
	}
	return (0);
}

char	**ft_put_tet(char **tab, t_block *tetri, int pos_x, int pos_y)
{
	int i;

	i = 0;
	while (i < 4)
	{
		tab[tetri->x[i] + pos_x][tetri->y[i] + pos_y] = tetri->letter;
		i++;
	}
	return (tab);
}

char	**ft_delete_tetri(char **tab, t_block *tetri)
{
	int x;
	int y;

	x = 0;
	while (x < g_size)
	{
		y = 0;
		while (y < g_size)
		{
			if (tab[x][y] == tetri->letter)
				tab[x][y] = '.';
			y++;
		}
		x++;
	}
	return (tab);
}

char	**ft_solve(char **tab, t_block *tetri)
{
	int		x;
	int		y;
	char	**tmp;

	if (!tetri->next)
		return (tab);
	tmp = NULL;
	x = -1;
	while (++x < g_size)
	{
		y = 0;
		while (y <= g_size)
		{
			if (tab[x][y] == '.')
			{
				if (!ft_check_position(tab, tetri, x, y))
					tmp = ft_solve(ft_put_tet(tab, tetri, x, y), tetri->next);
			}
			if (tmp)
				return (tmp);
			tab = ft_delete_tetri(tab, tetri);
			++y;
		}
	}
	return (NULL);
}

char	**ft_result(t_block *tetri, int size)
{
	char	**tab;

	tab = NULL;
	g_size = size;
	while (!tab)
	{
		tab = ft_create_map(tab, g_size);
		tab = ft_solve(tab, tetri);
		g_size++;
	}
	return (tab);
}
