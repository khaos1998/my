/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <cristian-ceban@mail.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 19:49:17 by cciobanu          #+#    #+#             */
/*   Updated: 2016/10/22 11:22:22 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	len;

	if (*to_find == '\0')
		return ((char *)str);
	len = ft_strlen(to_find);
	while (*str != '\0' && n >= len)
	{
		if (ft_strncmp(str, to_find, len) == 0)
			return ((char *)str);
		str++;
		n--;
	}
	return (NULL);
}
