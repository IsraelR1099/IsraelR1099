# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 13:14:50 by irifarac          #+#    #+#              #
#    Updated: 2022/05/27 14:09:37 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

all: $(NAME)


$(NAME): $(OBJ)
	cd Libft && make all
	gcc $(CFLAGS) $(SRC) -o $@
	@echo "Compilado"

clean:
	rm -f $(OBJ)
	@echo "Objetos borrados"

fclean: clean
	rm -f $(NAME)
	@echo "Ejecutable borrado"

re: fclean all

.PHONY: all clean fclean re

