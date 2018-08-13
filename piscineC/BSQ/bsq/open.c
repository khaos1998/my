/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 14:04:33 by cciobanu          #+#    #+#             */
/*   Updated: 2016/08/22 16:44:13 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*open_and_read(char *f)
{
	char *buff;
	int buff_size;
	int fd;
	int ret;

	buff_size=size(f);
	buff=malloc(sizeof(char)*buff_size);
	fd=open(f,O_RDONLY);
	ret=read(fd,buff,buff_size);
	buff[buff_size]='\0';
	ft_putstr(buff);
	return(buff);
}
