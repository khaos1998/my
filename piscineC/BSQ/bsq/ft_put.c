/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 13:34:16 by cciobanu          #+#    #+#             */
/*   Updated: 2016/08/22 14:39:36 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int index;

	index = 0;
	while (str[index] != '\0')
	{
		ft_putchar(str[index]);
		index++;
	}
}

void	ft_putnbr(int nb)
{
	unsigned int nbr;
	unsigned int num1;

	if (nb < 0)
	{
		ft_putchar('-');
		num1 = nb * -1;
	}
	else
		num1 = nb;
	nbr = num1 % 10;
	if (num1 <= 9)
		ft_putchar(num1 + '0');
	else
	{
		ft_putnbr(num1 / 10);
		ft_putchar(nbr + '0');
	}
}
