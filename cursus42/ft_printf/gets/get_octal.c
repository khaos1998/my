/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_octal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:00:25 by cciobanu          #+#    #+#             */
/*   Updated: 2017/11/21 21:30:55 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*get_octal(t_tags *tags, va_list arg)
{
	uintmax_t	value;
	char		*octal;
	char		*new_octal;

	value = get_u_value(tags, arg);
	if (!value && tags->set_precision == true)
		octal = ft_strdup("");
	else
		octal = ft_itoa_base(value, 8);
	precision(tags, &octal);
	if (tags->flags.sharp == true &&
		tags->flags.zero == false && octal[0] != '0')
	{
		new_octal = ft_strjoin("0", octal);
		free(octal);
		return (new_octal);
	}
	return (octal);
}
