/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <cristian-ceban@mail.ru>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 19:13:42 by cciobanu          #+#    #+#             */
/*   Updated: 2017/04/01 09:44:56 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1
# define EOL '\n'
# define ERROR -1
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int	get_next_line(int const fd, char **line);

#endif
