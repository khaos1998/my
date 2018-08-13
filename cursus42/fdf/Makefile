# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cciobanu <ccioabnu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/20 17:38:05 by cciobanu          #+#    #+#              #
#    Updated: 2017/11/29 16:35:07 by cciobanu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
EFLAGS = -Wall -Wextra -Werror
MFLAGS = -lmlx -framework OpenGL -framework AppKit -lm
SRC = 	fdf_calculate.c \
		fdf_draw.c \
		fdf_hook.c \
		fdf_read.c \
		main.c
OBJ = $(patsubst %.c,%.o,$(SRC))
LIB_H = libft/libft.h
LIB = libft/libft.a

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(EFLAGS)  $(LIB_H) -c $(SRC) 
	gcc -o $(NAME) $(OBJ) $(LIB) $(EFLAGS) $(MFLAGS)

clean:
	rm -rf $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -rf 	$(NAME)
	make -C libft/ fclean

re: fclean all
