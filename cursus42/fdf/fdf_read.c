/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <ccioabnu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 16:42:30 by cciobanu          #+#    #+#             */
/*   Updated: 2017/11/24 18:40:18 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_len(char *path)
{
	int		fd;
	int		size;
	char	*buf;
	int		ret;

	size = 0;
	buf = ft_strnew(100);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Cannot open file");
		exit(1);
	}
	while ((ret = read(fd, buf, 100)) > 0)
	{
		if (ret == -1)
		{
			ft_putstr("Read error");
			exit(1);
		}
		size = size + ret;
	}
	free(buf);
	close(fd);
	return (size);
}

t_point		**fdf_read(t_win *fdf)
{
	t_point **tab;
	int		i;
	int		fd;
	char	*temp;

	i = 0;
	tab = (t_point **)malloc(sizeof(t_point) * ft_len(fdf->path));
	if (!(fd = open(fdf->path, O_RDONLY)))
	{
		ft_putstr("Cannot open file");
		exit(1);
	}
	while (get_next_line(fd, &temp) == 1)
	{
		tab[i] = fdf_create_line(temp, i, fdf);
		i++;
	}
	tab[i] = fdf_create_line(temp, i, fdf);
	fdf->map_h = i;
	close(fd);
	return (tab);
}

t_point		*fdf_create_line(char *temp, int pos, t_win *fdf)
{
	t_point *line;
	char	**str_line;
	int		size;
	int		i;

	i = 0;
	str_line = ft_strsplit(temp, ' ');
	size = fdf_map_w(str_line);
	if (size > fdf->map_w)
		fdf->map_w = size;
	line = (t_point *)malloc(sizeof(t_point) * fdf->map_w);
	while (str_line[i] != NULL)
	{
		line[i] = fdf_point(pos, i, ft_atoi(str_line[i]));
		if (line[i].d3z > fdf->max)
			fdf->max = line[i].d3z;
		i++;
	}
	return (line);
}

int			fdf_map_w(char **temp)
{
	int i;

	i = 0;
	while (temp[i] != NULL)
		i++;
	return (i);
}

t_point		fdf_point(int x, int y, int z)
{
	t_point point;

	point.d3x = x;
	point.d3y = y;
	point.d3z = z;
	return (point);
}
