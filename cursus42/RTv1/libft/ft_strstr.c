/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <cristian-ceban@mail.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 19:29:24 by cciobanu          #+#    #+#             */
/*   Updated: 2016/10/22 12:24:36 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*str;
	int		i;
	int		j;

	str = (char*)haystack;
	i = 0;
	if (!*needle)
		return (str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == needle[j])
		{
			if (!(needle[j + 1]))
				return (str + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
