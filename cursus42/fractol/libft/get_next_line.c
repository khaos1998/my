/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <cristian-ceban@mail.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 19:16:01 by cciobanu          #+#    #+#             */
/*   Updated: 2016/12/24 10:41:15 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_read(int fd, char **str)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*temp;

	ret = -2;
	temp = NULL;
	while ((!ft_strchr(*str, EOL)))
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) <= 0)
			return (ret);
		buf[ret] = 0;
		temp = *str;
		if (!(*str = ft_strjoin(*str, buf)))
			return (ERROR);
		ft_strdel(&temp);
		if (ret < BUFF_SIZE)
			return (ret);
	}
	return (ret);
}

static char	*ft_gnl(char *str, char **line)
{
	char	*temp;
	char	*del;

	del = str;
	if (str && (temp = ft_strchr(str, EOL)))
	{
		*line = ft_strsub(str, 0, ft_strlen(str) - ft_strlen(temp));
		str = ft_strdup(temp + 1);
		ft_strdel(&del);
	}
	else
	{
		*line = ft_strdup(str);
		ft_strclr(str);
	}
	return (str);
}

int			get_next_line(int const fd, char **line)
{
	static char	*stock[1024];
	int			ret;

	if (fd < 0 || !line || fd > 1024)
		return (ERROR);
	if (!stock[fd])
		stock[fd] = ft_strnew(0);
	if ((ret = ft_read(fd, &stock[fd])) == ERROR)
		return (ERROR);
	stock[fd] = ft_gnl(stock[fd], line);
	if ((!ret && !ft_strlen(stock[fd]) && !ft_strlen(*line)))
		return (0);
	else
		return (1);
}
