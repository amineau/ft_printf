# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amineau <amineau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/25 13:15:17 by amineau           #+#    #+#              #
#    Updated: 2016/03/20 12:06:27 by amineau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
EXE = ft_printf
CC= gcc
LFTPATCH= ./libft/
LIBS= -L$(LFTPATCH) -lft 
FLAGS= -Wall -Wextra -Werror
SRC=ft_printf.c \
	ft_stock.c \
	ft_list.c \
	ft_algo.c \
	ft_straddc.c \
	ft_itoa_double.c \
	ft_itoa_scien.c \
	ft_itoa_fonc.c \
	ft_arrondi.c \
	ft_nbrdigit.c \
	ft_putwint.c \
	ft_putwchar.c \
	ft_cntwint.c \
	ft_libft_wchar.c \
	ft_atof.c \
	ft_wildcard.c \
	ft_recup_arg.c \
	ft_justif.c \
	ft_zero_justif.c \
	ft_integer.c \
	ft_floater.c \
	ft_wchar.c \

OBJ= $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	make -C $(LFTPATCH)
	$(CC) $(FLAGS) -c $(SRC)
	cp libft/libft.a $(NAME)
	ar r $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(EXE)

re: fclean all
