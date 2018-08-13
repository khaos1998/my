/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 20:45:58 by cciobanu          #+#    #+#             */
/*   Updated: 2017/11/21 21:07:40 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

#define BYTE_1 "0xxxxxxx"
#define BYTE_2 "110xxxxx 10xxxxxx"
#define BYTE_3 "1110xxxx 10xxxxxx 10xxxxxx"
#define BYTE_4 "11110xxx 10xxxxxx 10xxxxxx 10xxxxxx"

int		ft_pow(int a, int b)
{
	int res;

	res = 1;
	while (b > 0)
	{
		res = res * a;
		b--;
	}
	return (res);
}

int		ft_to_dec(char *bit)
{
	int	res;
	int	i;
	int	len;

	res = 0;
	i = 0;
	len = ft_strlen(bit);
	while (bit[i] != '\0')
	{
		res = res + (int)(bit[i] - '0') * ft_pow(2, len - 1);
		i++;
		len--;
	}
	return (res);
}

char	**ft_change(char *bin, char *b)
{
	int		len_bin;
	int		len_byte;
	size_t	i;
	char	*byte;
	char	**new_byte;

	byte = ft_strdup(b);
	len_bin = ft_strlen(bin) - 1;
	len_byte = ft_strlen(byte) - 1;
	while (len_bin >= 0 && len_byte >= 0)
	{
		if (byte[len_byte] == 'x')
		{
			byte[len_byte] = bin[len_bin];
			len_bin--;
		}
		len_byte--;
	}
	i = 0;
	while (i++ < ft_strlen(byte))
		if (byte[i] == 'x')
			byte[i] = '0';
	new_byte = ft_strsplit(byte, ' ');
	free(byte);
	return (new_byte);
}

void	ft_putwchar(wchar_t c)
{
	int		chr;
	char	*binary;
	char	**bytes;
	int		i;

	i = 0;
	chr = (int)c;
	binary = ft_itoa_base(chr, 2);
	if (ft_strlen(binary) <= 7)
		bytes = ft_change(binary, BYTE_1);
	else if (ft_strlen(binary) <= 11)
		bytes = ft_change(binary, BYTE_2);
	else if (ft_strlen(binary) <= 16)
		bytes = ft_change(binary, BYTE_3);
	else
		bytes = ft_change(binary, BYTE_4);
	while (bytes[i])
	{
		ft_putchar(ft_to_dec(bytes[i]));
		free(bytes[i]);
		i++;
	}
	free(binary);
	free(bytes);
}
