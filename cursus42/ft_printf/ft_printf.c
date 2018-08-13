/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:04:25 by cciobanu          #+#    #+#             */
/*   Updated: 2018/01/05 01:02:12 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_printf(char *str, ...)
{
	va_list		arg;
	t_format	format;

	ft_bzero(&format, sizeof(t_format));
	format.str = str;
	va_start(arg, str);
	analyse_format(&format, arg);
	va_end(arg);
	return (format.written);
}
