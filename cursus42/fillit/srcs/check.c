/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <cristian-ceban@mail.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:44:02 by cciobanu          #+#    #+#             */
/*   Updated: 2016/11/19 13:42:56 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_first_check(char *str)
{
	int dot;
	int diez;
	int nl;

	dot = 0;
	diez = 0;
	nl = 0;
	while (*str)
	{
		if (*str == '.' || *str == '#' || *str == '\n')
		{
			if (*str == '.')
				dot++;
			if (*str == '#')
				diez++;
			if (*str == '\n')
				nl++;
		}
		else
			ft_error("error");
		str++;
	}
	if ((diez % 4) || (dot % 12) || ((nl + 1) % 5) || (diez < 4))
		ft_error("error");
	return (diez / 4);
}

char	*ft_recursive_check(char *str, int i)
{
	if (str[i + 1] == '#')
	{
		str[i + 1] = 'c';
		ft_recursive_check(str, i + 1);
	}
	if ((i + 5 <= 20) && (str[i + 5] == '#'))
	{
		str[i + 5] = 'c';
		ft_recursive_check(str, i + 5);
	}
	if ((i - 1 >= 0) && (str[i - 1] == '#'))
	{
		str[i - 1] = 'c';
		ft_recursive_check(str, i - 1);
	}
	return (str);
}

int		ft_number(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if (*str == 'c')
			i++;
		str++;
	}
	return (i);
}

void	ft_second_check(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '#')
		i++;
	str[i] = 'c';
	str = ft_recursive_check(str, i);
	if (ft_number(str) != 4)
		ft_error("error");
	i = 0;
	while (str[i])
	{
		if (str[i] == 'c')
			str[i] = '#';
		i++;
	}
}

void	line_check(char *str)
{
	int i;
	int n;

	i = 20;
	n = 21;
	while (str[i] != '\0')
	{
		if (str[i] != '\n')
			ft_error("error");
		i = i + n;
	}
}
