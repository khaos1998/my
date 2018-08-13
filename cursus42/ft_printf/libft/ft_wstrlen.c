/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:48:01 by cciobanu          #+#    #+#             */
/*   Updated: 2017/11/21 21:17:05 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	wstrlen(wchar_t *str)
{
	int len;

	len = 0;
	while (*str)
	{
		len += wcharlen(*str);
		str++;
	}
	return (len);
}
