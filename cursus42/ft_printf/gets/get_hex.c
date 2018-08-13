/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:55:47 by cciobanu          #+#    #+#             */
/*   Updated: 2017/11/23 16:41:03 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*add_sharp(t_tags *tags, char *hex)
{
	char *new_hex;

	if (tags->width_precision == false && hex[0] == '0' &&
		tags->set_precision == false)
		return (hex);
	if (tags->specifier == HEX_UPPER)
		new_hex = ft_strjoin("0X", hex);
	if (tags->specifier == HEX_LOWER)
		new_hex = ft_strjoin("0x", hex);
	free(hex);
	return (new_hex);
}

char	*get_hex(t_tags *tags, va_list arg)
{
	uintmax_t	value;
	char		*hex;
	t_bool		wide;

	wide = false;
	value = get_u_value(tags, arg);
	if (value == 0 && tags->set_precision == true)
	{
		hex = ft_strdup("");
		wide = true;
	}
	else
		hex = ft_itoa_base(value, 16);
	precision(tags, &hex);
	if (tags->specifier == HEX_UPPER)
		ft_strtoupper(hex);
	else
		ft_strtolower(hex);
	if (tags->flags.sharp == true && wide == false)
		return (add_sharp(tags, hex));
	return (hex);
}
