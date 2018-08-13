/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciobanu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 10:08:04 by cciobanu          #+#    #+#             */
/*   Updated: 2016/11/19 10:27:05 by cciobanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef	struct	s_block
{
	char			letter;
	char			*tetri;
	int				x[4];
	int				y[4];
	struct s_block	*next;
}				t_block;

void			ft_error(char *str);
char			*ft_reading(char *input);
t_block			*ft_create(char *str);
int				ft_first_check(char *str);
void			ft_second_check(char *str);
char			*ft_recursive_check(char *str, int i);
int				ft_number(char *str);
t_block			*ft_first_xy(t_block *block, char *str);
t_block			*ft_sec_xy(t_block *block);
t_block			*ft_xy(t_block *block);
char			**ft_create_map(char **tab, int size);
int				map_size(t_block *tetri);
int				ft_check_position(char **tab, t_block *tetri, int x, int y);
char			**ft_put_tet(char **tab, t_block *tetri, int pos_x, int pos_y);
char			**ft_delete_tetri(char **tab, t_block *tetri);
char			**ft_solve(char **tab, t_block *tetri);
char			**ft_result(t_block *tetri, int size);
void			line_check(char *str);
#endif
