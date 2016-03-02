# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amineau <amineau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/25 13:15:17 by amineau           #+#    #+#              #
#    Updated: 2016/03/02 16:08:37 by amineau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

CC = gcc
LFTPATCH = ./libft/
LIBS = -L$(LFTPATCH) -lft 
FLAGS = -Wall -Wextra -Werror
SRC = main.c \
	ft_printf.c \
	ft_stock.c \
	ft_list.c \
	ft_algo.c \
	ft_straddc.c \
	ft_itoa_double.c \
	ft_arrondi.c

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	make -C $(LFTPATCH) re
	$(CC) $(FLAGS) -c $(SRC) 
	$(CC) $(OBJ) $(LIBS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
