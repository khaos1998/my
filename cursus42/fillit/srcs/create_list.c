/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <cristian-ceban@mail.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:20:00 by cciobanu          #+#    #+#             */
/*   Updated: 2016/11/19 13:40:15 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_block	*ft_create(char *str)
{
	t_block *tmp;
	t_block *block;
	int		tet;
	int		j;
	char	let;

	let = 'A';
	j = 0;
	if (!(block = (t_block *)malloc(sizeof(t_block))))
		return (NULL);
	tmp = block;
	tet = ft_first_check(str);
	while (tet > 0)
	{
		tmp->tetri = ft_strndup(&str[j], 20);
		ft_second_check(tmp->tetri);
		tmp->letter = let++;
		j = j + 21;
		if (!(tmp->next = (t_block *)malloc(sizeof(t_block))))
			return (NULL);
		tet--;
		tmp = tmp->next;
	}
	tmp->next = NULL;
	return (block);
}
