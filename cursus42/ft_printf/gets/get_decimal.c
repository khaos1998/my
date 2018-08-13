/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_decimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 19:45:52 by cciobanu          #+#    #+#             */
/*   Updated: 2017/11/21 21:25:29 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*check_sign(t_tags *tags, char *value)
{
	char *new_val;

	if (tags->flags.sign == true && ft_isdigit(value[0]))
	{
		new_val = ft_strjoin("+", value);
		free(value);
		return (new_val);
	}
	if (tags->flags.space == true && ft_isdigit(value[0]))
	{
		new_val = ft_strjoin(" ", value);
		free(value);
		return (new_val);
	}
	return (value);
}

char	*get_decimal(t_tags *tags, va_list arg)
{
	uintmax_t	u_value;
	intmax_t	s_value;
	char		*value;

	if (tags->specifier == U_DECIMAL)
	{
		u_value = get_u_value(tags, arg);
		if (u_value == 0 && tags->set_precision == true && tags->precision == 0)
			value = ft_strdup("");
		else
			value = ft_itoa_ularge(u_value);
	}
	else
	{
		s_value = get_s_value(tags, arg);
		if (s_value == 0 && tags->set_precision == true && tags->precision == 0)
			value = ft_strdup("");
		else
			value = ft_itoa_large(s_value);
	}
	precision(tags, &value);
	return (check_sign(tags, value));
}
