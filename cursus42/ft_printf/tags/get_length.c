/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:27:38 by cciobanu          #+#    #+#             */
/*   Updated: 2017/11/23 18:39:40 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_length	add_length(char chr, char chr2)
{
	if (chr == 'h')
		return (chr2 == 'h' ? HH : H);
	if (chr == 'l')
		return (chr2 == 'l' ? LL : L);
	if (chr == 'z')
		return (Z);
	if (chr == 'j')
		return (J);
	return (DEFAULT);
}

void		get_length(t_tags *tags, t_format *format)
{
	char		chr;
	char		chr2;
	t_length	old;

	old = tags->length;
	if ((!(chr = *get_pos(format))))
		return ;
	chr2 = *(get_pos(format) + 1);
	tags->length = add_length(chr, chr2);
	if (tags->length != DEFAULT)
		format->position++;
	if (tags->length == HH || tags->length == LL)
		format->position++;
	if (old > tags->length)
		tags->length = old;
}
