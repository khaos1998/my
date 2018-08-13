# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cciobanu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/22 13:20:41 by cciobanu          #+#    #+#              #
#    Updated: 2016/08/22 16:41:30 by cciobanu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=bsq
FLAG=-Wall -Wextra -Werror
SRC=main.c validare.c ft_put.c size.c open.c
SRC2=main.o validare.o ft_put.o size.o open.o

all:
	@gcc -c $(SRC)
	@gcc $(FLAG) $(SRC2) -o $(NAME)

clean:
	@rm -f $(SRC2)

fclean: clean
	@rm -f $(NAME)
