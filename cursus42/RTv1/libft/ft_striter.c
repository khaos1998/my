/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <cristian-ceban@mail.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 20:07:13 by cciobanu          #+#    #+#             */
/*   Updated: 2016/10/20 15:54:44 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	size_t	i;
	char	*str;

	str = (char*)s;
	if (str && f)
	{
		i = 0;
		while (str[i])
		{
			(*f)(&(str[i]));
			i++;
		}
	}
}
