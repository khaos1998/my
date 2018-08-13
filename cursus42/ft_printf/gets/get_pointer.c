/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:01:42 by cciobanu          #+#    #+#             */
/*   Updated: 2017/12/20 15:11:44 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*get_pointer(t_tags *tags, va_list arg)
{
	uintmax_t	value;
	char		*pointer;
	char		*pointer2;

	value = (long)va_arg(arg, void*);
	if (value == 0 && tags->set_precision == true)
		pointer = ft_strdup("");
	else
		pointer = ft_itoa_base(value, 16);
	ft_strtolower(pointer);
	precision(tags, &pointer);
	pointer2 = ft_strjoin("0x", pointer);
	free(pointer);
	return (pointer2);
}
