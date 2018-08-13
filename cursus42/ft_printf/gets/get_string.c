/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:02:34 by cciobanu          #+#    #+#             */
/*   Updated: 2017/11/22 21:18:22 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*set_str_precision(t_tags *tags, char *str)
{
	char	*str_precision;

	if (ft_strlen(str) > tags->precision && tags->set_precision == true)
	{
		str_precision = ft_strnew(tags->precision);
		ft_strncpy(str_precision, str, tags->precision);
	}
	else
		str_precision = ft_strdup(str);
	return (str_precision);
}

char	*get_string(t_tags *tags, va_list arg)
{
	char	*str;

	if (!(str = va_arg(arg, char*)))
	{
		if (tags->set_precision == true || tags->width_precision == true)
			str = ft_strdup("");
		else
			return (ft_strdup("(null)"));
	}
	return (set_str_precision(tags, str));
}
