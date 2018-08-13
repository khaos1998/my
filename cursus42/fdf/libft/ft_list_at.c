/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 13:59:57 by cciobanu          #+#    #+#             */
/*   Updated: 2016/10/22 16:05:24 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_at(t_list *begin_list, size_t nbr)
{
	size_t i;

	i = 1;
	while (i < nbr && begin_list->next != 0)
	{
		i++;
		begin_list = begin_list->next;
	}
	if (i == nbr)
		return (begin_list);
	else
		return (0);
}
