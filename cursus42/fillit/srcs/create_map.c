/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <cristian-ceban@mail.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:06:13 by cciobanu          #+#    #+#             */
/*   Updated: 2016/11/19 10:16:08 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_create_map(char **tab, int size)
{
	int		x;
	int		y;

	x = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	while (x < size)
	{
		tab[x] = ft_strnew(size);
		y = 0;
		while (y < size)
		{
			tab[x][y] = '.';
			y++;
		}
		x++;
	}
	tab[x] = NULL;
	return (tab);
}

int		map_size(t_block *tetri)
{
	int i;
	int max;

	i = 0;
	max = 2;
	while (tetri->next)
	{
		i++;
		tetri = tetri->next;
	}
	while (max * max < i * 4)
		max++;
	return (max);
}
