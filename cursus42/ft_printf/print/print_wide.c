/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wide.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:25:21 by cciobanu          #+#    #+#             */
/*   Updated: 2017/11/23 16:29:48 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void	wchar_width(t_tags *tags, t_format *format, size_t len)
{
	int		n;
	char	chr;

	if (tags->flags.zero == true)
		chr = '0';
	else
		chr = ' ';
	n = tags->width - len;
	while (n > 0)
	{
		ft_putchar(chr);
		format->written++;
		n--;
	}
}

void	print_wchar(t_tags *tags, t_format *format, wchar_t chr)
{
	size_t len;

	len = wcharlen(chr);
	if (tags->flags.left_justify == false)
	{
		wchar_width(tags, format, len);
		ft_putwchar(chr);
	}
	else
	{
		ft_putwchar(chr);
		wchar_width(tags, format, len);
	}
	format->written += len;
}

size_t	calc_len(wchar_t *str, t_tags *tags)
{
	size_t index;
	size_t len;
	size_t prec;

	len = 0;
	prec = (size_t)tags->precision;
	while (*str != '\0' && prec != 0)
	{
		index = wcharlen(*str);
		if ((int)(prec - index) < 0)
			break ;
		prec -= index;
		str++;
		len += index;
	}
	return (len);
}

void	printn_wstr(wchar_t *str, size_t n)
{
	size_t bytes;

	while (*str != '\0' && n > 0)
	{
		bytes = wcharlen(*str);
		ft_putwchar(*str);
		str++;
		n -= bytes;
	}
}

void	print_wstr(t_tags *tags, t_format *format, va_list arg)
{
	wchar_t	*str;
	size_t	len;

	str = va_arg(arg, wchar_t*);
	if (str == NULL)
		str = L"(null)";
	if (tags->set_precision == true)
		len = calc_len(str, tags);
	else
		len = wstrlen(str);
	if (tags->flags.left_justify == false)
	{
		wchar_width(tags, format, len);
		printn_wstr(str, len);
	}
	else
	{
		printn_wstr(str, len);
		wchar_width(tags, format, len);
	}
	format->written += len;
}
