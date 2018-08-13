#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: cciobanu <cristian-ceban@mail.ru>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/11/16 17:33:21 by cciobanu          #+#    #+#             *#
#*   Updated: 2016/11/18 21:56:39 by cciobanu         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = fillit
LIBINC = -I ./libft
INCLUDES = -I includes -I libft
COMP =gcc
CC = gcc -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME):
	@make -C ./libft
	@$(CC) -c srcs/*.c $(INCLUDES)
	@gcc *.o libft/libft.a -o $(NAME)

clean:
	@$(RM) *.o
	@$(RM) ./libft/*.o

fclean: clean
	@$(RM) $(NAME)
	@$(RM) ./libft/libft.a

re:  fclean all
