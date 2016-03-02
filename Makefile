# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amineau <amineau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/25 13:15:17 by amineau           #+#    #+#              #
#    Updated: 2016/03/02 21:01:14 by amineau          ###   ########.fr        #
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
	ft_arrondi.c \

OBJ= $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	make -C $(LFTPATCH)
	$(CC) $(FLAGS) -c $(SRC)
	cp libft/libft.a $(NAME)
	ar r $(NAME) $(OBJ)
	ranlib $(NAME)
ss:
	make -C $(LFTPATCH)
	$(CC) $(FLAGS) -c $(SRC) main.c
	$(CC) $(OBJ) main.o $(LIBS) -o $(EXE)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(EXE)

re: fclean all
