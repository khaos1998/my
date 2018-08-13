/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 14:29:12 by cciobanu          #+#    #+#             */
/*   Updated: 2016/08/22 16:31:46 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
int		size(char *str)
{
	int fd;
	int i;
	int ret;
	char buff[1];

	i=0;
	fd=open(str, O_RDONLY);
	while((ret=read(fd,buff,1)!=0))
		i++;
	close(fd);
	return(i);
}
