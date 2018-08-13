/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:47:23 by cciobanu          #+#    #+#             */
/*   Updated: 2017/11/21 21:07:28 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	wcharlen(wchar_t chr)
{
	if (chr <= 0x7F)
		return (1);
	if (chr <= 0x7FF)
		return (2);
	if (chr <= 0xFFFF)
		return (3);
	if (chr <= 0x10FFFF)
		return (4);
	return (0);
}
