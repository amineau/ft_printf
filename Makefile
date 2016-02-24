NAME = ft_printf

CC = gcc
LFTPATCH = ./libft/
LIBS = -L$(LFTPATCH) -lft 
FLAGS = -Wall -Werror -Wextra
SRC = main.c \
	ft_printf.c \

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	make -C $(LFTPATCH)
	$(CC) $(FLAGS) -c $(SRC) 
	$(CC) $(OBJ) $(LIBS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
