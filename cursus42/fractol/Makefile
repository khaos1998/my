# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cciobanu <ccioabnu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/20 17:38:05 by cciobanu          #+#    #+#              #
#    Updated: 2018/02/21 19:55:35 by cciobanu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
EFLAGS = -Wall -Wextra -Werror
MFLAGS = -lmlx -framework OpenGL -framework AppKit -lm
SRC = 	fractol_hook.c \
		manndel.c \
		julia.c \
		newton.c \
		image.c \
		main.c 
OBJ = $(patsubst %.c,%.o,$(SRC))
LIB_H = libft/libft.h
LIB = libft/libft.a

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(EFLAGS) $(LIB_H) -c $(SRC)
	gcc -o $(NAME) $(OBJ) $(LIB) $(EFLAGS) $(MFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf 	$(NAME)
	make -C libft/ fclean

re: fclean all
