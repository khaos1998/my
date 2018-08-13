/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:04:45 by cciobanu          #+#    #+#             */
/*   Updated: 2017/11/23 16:00:27 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	set_precision_int(t_tags *tags, char **str)
{
	char	*new;
	int		need;
	int		len;
	int		sign;
	int		prec;

	if (tags->set_precision == true)
		prec = tags->precision;
	else
		prec = 0;
	len = ft_strlen(*str);
	need = prec - len;
	sign = (ft_isdigit(**str) ? 0 : 1);
	need += sign;
	if (need > 0)
	{
		new = ft_strnew(len + need + sign);
		if (sign == 1)
			new[0] = **str;
		ft_memset(new + sign, '0', need);
		ft_strcpy(new + sign + need, *str + sign);
		free(*str);
		*str = new;
	}
}

void	set_precision(t_tags *tags, char **str)
{
	char	*new;
	int		need;
	int		len;
	int		prec;

	if (tags->width_precision == true)
	{
		if (tags->flags.sharp == true || tags->specifier == POINTER)
			prec = tags->width - 2;
		else
			prec = tags->width;
		tags->width = 0;
	}
	else
		prec = tags->precision;
	len = ft_strlen(*str);
	need = prec - len;
	if (need > 0)
	{
		new = ft_strnew(len + need);
		ft_memset(new, '0', need);
		ft_strcpy(new + need, *str);
		free(*str);
		*str = new;
	}
}

void	precision(t_tags *tags, char **str)
{
	if (tags->set_precision == true || tags->width_precision == true)
	{
		if (tags->specifier == DECIMAL || tags->specifier == U_DECIMAL)
			set_precision_int(tags, str);
		else
			set_precision(tags, str);
	}
}
