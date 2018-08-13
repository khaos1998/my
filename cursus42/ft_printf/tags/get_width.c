/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:24:38 by cciobanu          #+#    #+#             */
/*   Updated: 2017/11/23 18:41:09 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	get_width(t_tags *tags, t_format *format, va_list arg)
{
	char			chr;
	unsigned int	old;

	old = tags->width;
	if ((chr = *get_pos(format)) == '*')
	{
		tags->width = va_arg(arg, unsigned int);
		format->position++;
	}
	else if ((chr = *get_pos(format)) && !ft_isdigit(chr))
		tags->width = 0;
	else
	{
		while ((chr = *get_pos(format)) && (ft_isdigit(chr)))
		{
			atoi_add_digit(chr, &(tags->width));
			format->position++;
		}
	}
	if (old > tags->width)
		tags->width = old;
}
