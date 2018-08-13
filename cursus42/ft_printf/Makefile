# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cciobanu <ccioabnu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/20 17:38:05 by cciobanu          #+#    #+#              #
#    Updated: 2018/01/05 01:10:29 by cciobanu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS += -Wall -Wextra -Werror

SRC = ft_printf.c 
TAGFILES = analyse.c \
		get_flags.c \
		get_length.c \
		get_precision.c \
		get_specifier.c \
		get_width.c \
		validate_tags.c 
GETFILES = get_int_value.c \
		get_octal.c \
		get_string.c \
		get_decimal.c \
		get_hex.c \
		get_pointer.c \
		set_precision.c
PRTFILES = print.c \
	   	print_invalid.c \
		print_wide.c 

LIBFILES =	ft_strlen.c \
			ft_strdup.c \
			ft_strnew.c \
			ft_strchr.c \
			ft_memalloc.c \
			ft_memcpy.c \
			ft_strcpy.c \
			ft_memset.c \
			ft_strcmp.c \
			ft_memmove.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_strjoin.c \
			ft_isdigit.c \
			ft_bzero.c \
			ft_strncpy.c \
			ft_tolower.c \
			ft_strcat.c \
			ft_toupper.c \
			ft_strtoupper.c \
			ft_strtolower.c \
			ft_atoi_add_digit.c \
			ft_itoa_base.c \
			ft_itoa_large.c \
			ft_putwchar.c \
			ft_strsub.c \
			ft_wcharlen.c \
			ft_strsplit.c \
			ft_wstrlen.c \
			ft_memdel.c \
			ft_itoa_ularge.c 
TAGSRC = $(addprefix tags/, $(TAGFILES))
PRTSRC = $(addprefix print/, $(PRTFILES))
GETSRC = $(addprefix gets/, $(GETFILES))
LIBSRC = $(addprefix libft/, $(LIBFILES))
SRCFILES += $(SRC)  $(LIBFILES)  $(TAGFILES)  $(PRTFILES)  $(GETFILES)
OBJDIR = ./obj/
INCDIR = ./includes/
OBJ = $(SRCFILES:.c=.o)
OBJS = $(addprefix $(OBJDIR), $(OBJ))


all: $(NAME)

$(NAME):
	@gcc $(CFLAGS) -I$(INCDIR) -c $(SRC) $(TAGSRC) $(PRTSRC) $(GETSRC) $(LIBSRC)
	@mkdir -p $(OBJDIR)
	@mv $(OBJ) $(OBJDIR)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
		@rm -rf $(OBJS)
		@rm -rf $(OBJDIR)

fclean: clean 
		@rm -rf $(NAME)

re: fclean all
