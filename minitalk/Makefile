# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 09:34:40 by irifarac          #+#    #+#              #
#    Updated: 2022/05/18 14:05:03 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRC_CLIENT = client.c ft_utils.c
SRC_SERVER = server.c ft_utils.c

OBJ_S = $(SRC_SERVER:.c=.o)
OBJ_C = $(SRC_CLIENT:.c=.o)

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_CLIENT): $(OBJ_C)
		gcc $(CFLAGS) $(SRC_CLIENT) -o $(NAME_CLIENT)
$(NAME_SERVER): $(OBJ_S)
		gcc $(CFLAGS) $(SRC_SERVER) -o $(NAME_SERVER)

.c.o:
	@echo "Compiling"
	gcc $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ_C)
	rm -f $(OBJ_S)
	@echo "Objets cleaned"

fclean: clean
	rm -f $(NAME_CLIENT)
	rm -f $(NAME_SERVER)
	@echo "executable files cleaned"

re: fclean all

.PHONY: all clean fclean re
