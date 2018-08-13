/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <cristian-ceban@mail.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 20:20:48 by cciobanu          #+#    #+#             */
/*   Updated: 2016/10/20 15:51:14 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*str;
	char			*str_new;

	str = (char*)s;
	if (str && f)
	{
		i = 0;
		str_new = ft_strnew(ft_strlen(str));
		if (!str_new)
			return (NULL);
		while (str[i])
		{
			str_new[i] = (*f)(str[i]);
			i++;
		}
		return (str_new);
	}
	return (NULL);
}
