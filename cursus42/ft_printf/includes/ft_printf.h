/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:27:37 by cciobanu          #+#    #+#             */
/*   Updated: 2017/11/23 18:43:42 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef enum	e_bool
{
	false, true
}				t_bool;
typedef enum	e_specifier
{
	INVALID, DECIMAL, U_DECIMAL, HEX_LOWER, HEX_UPPER, POINTER,
	OCTAL, STRING, CHAR, PERCENT
}				t_specifier;
typedef enum	e_length
{
	DEFAULT, HH, H, L, LL, J, Z
}				t_length;

typedef struct	s_flag
{
	t_bool zero;
	t_bool sign;
	t_bool left_justify;
	t_bool space;
	t_bool sharp;

}				t_flag;
typedef struct	s_format
{
	char	*str;
	int		position;
	int		written;
}				t_format;
typedef struct	s_tags
{
	unsigned int	precision;
	unsigned int	width;
	unsigned int	iter;
	t_length		length;
	t_bool			set_precision;
	t_bool			width_precision;
	t_flag			flags;
	t_specifier		specifier;
}				t_tags;

int				ft_printf(char *format, ...);
char			*get_pos(t_format *format);
t_bool			is_tag(char chr);
void			validate_flags(t_tags *tags);
t_bool			check_percent(t_format *format);
void			analyse_format(t_format *format, va_list arg);
void			analyse_tags(t_format *format, va_list arg);
void			get_tags(t_tags *tags, t_format *format, va_list arg);
void			get_width(t_tags *tags, t_format *format, va_list arg);
void			get_flags(t_tags *tags, t_format *format);
void			get_precision(t_tags *tags, t_format *format, va_list arg);
void			get_length(t_tags *tags, t_format *format);
void			get_specifier(t_tags *tags, t_format *format);
void			print_format(t_tags *tags, t_format *format, va_list arg);
char			*get_string(t_tags *tags, va_list arg);
char			*set_str_precision(t_tags *tags, char *str);
char			*get_str(t_tags *tags, va_list arg);
char			*get_octal(t_tags *tags, va_list arg);
char			width_char(t_tags *tags);
char			*get_pointer(t_tags *tags, va_list arg);
char			*get_hex(t_tags *tags, va_list arg);
char			*get_decimal(t_tags *tags, va_list arg);
void			print_char(t_tags *tags, t_format *format, char chr);
uintmax_t		get_u_value(t_tags *tags, va_list arg);
intmax_t		get_s_value(t_tags *tags, va_list arg);
char			*get_percent(t_tags *tags, t_format *format);
void			print_wstr(t_tags *tags, t_format *format, va_list arg);
void			print_wchar(t_tags *tags, t_format *format, wchar_t chr);
void			print(t_tags *tags, t_format *format, va_list arg);
void			precision(t_tags *tags, char **str);
void			print_invalid(t_tags *tags, t_format *format);
void			print_sign(t_tags *tags, t_format *format, char *str);
void			print_width(t_tags *tags, t_format *format, char *str);

#endif
