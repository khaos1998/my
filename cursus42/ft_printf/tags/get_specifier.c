/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:36:17 by cciobanu          #+#    #+#             */
/*   Updated: 2017/11/23 18:40:42 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_specifier		add_specifier(char chr)
{
	if (chr == 'd' || chr == 'i' || chr == 'D')
		return (DECIMAL);
	if (chr == 's' || chr == 'S')
		return (STRING);
	if (chr == 'p')
		return (POINTER);
	if (chr == 'x')
		return (HEX_LOWER);
	if (chr == 'X')
		return (HEX_UPPER);
	if (chr == 'u' || chr == 'U')
		return (U_DECIMAL);
	if (chr == 'o' || chr == 'O')
		return (OCTAL);
	if (chr == 'c' || chr == 'C')
		return (CHAR);
	if (chr == '%')
		return (PERCENT);
	return (INVALID);
}

void			get_specifier(t_tags *tags, t_format *format)
{
	char chr;

	if ((chr = *get_pos(format)) != '\0')
		tags->specifier = add_specifier(chr);
	if (tags->specifier == U_DECIMAL)
	{
		tags->flags.sign = false;
		tags->flags.space = false;
	}
	if (chr == 'U' || chr == 'O' || chr == 'D' || chr == 'C' || chr == 'S')
		tags->length = L;
	if (tags->specifier != INVALID)
		format->position++;
}
