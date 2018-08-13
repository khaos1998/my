/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_invalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:41:34 by cciobanu          #+#    #+#             */
/*   Updated: 2017/11/23 17:01:24 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_invalid(t_tags *tags, t_format *format)
{
	if (tags->set_precision == true || tags->width_precision == true ||
		tags->width > 0)
	{
		if (tags->flags.left_justify == true)
		{
			ft_putchar(*get_pos(format));
			print_width(tags, format, " ");
		}
		else
		{
			print_width(tags, format, " ");
			ft_putchar(*get_pos(format));
		}
		format->position++;
		format->written++;
	}
}

void	print_sign(t_tags *tags, t_format *format, char *str)
{
	ft_putchar(str[0]);
	print_width(tags, format, str);
	ft_putstr(str + 1);
}
