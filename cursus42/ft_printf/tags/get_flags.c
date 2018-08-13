/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:13:23 by cciobanu          #+#    #+#             */
/*   Updated: 2017/11/23 18:38:57 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	check_flag(t_bool *flag, t_format *format)
{
	*flag = true;
	format->position++;
}

void	get_flags(t_tags *tags, t_format *format)
{
	char chr;

	while ((chr = *get_pos(format)) &&
			(chr == '0' || chr == '+' || chr == '#' || chr == '-' ||
			chr == '-' || chr == ' '))
	{
		if (chr == '0')
			check_flag(&(tags->flags.zero), format);
		if (chr == '+')
			check_flag(&(tags->flags.sign), format);
		if (chr == '#')
			check_flag(&(tags->flags.sharp), format);
		if (chr == '-')
			check_flag(&(tags->flags.left_justify), format);
		if (chr == ' ')
			check_flag(&(tags->flags.space), format);
	}
}
