# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 09:34:40 by irifarac          #+#    #+#              #
#    Updated: 2022/05/19 11:27:48 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client
NAME_BONUSC = client_bonus
NAME_BONUSS = server_bonus
CFLAGS = -Wall -Wextra -Werror
INCLUDE = minitalk.h
AR = ar rcs

SRC_CLIENT = client.c ft_utils.c
SRC_SERVER = server.c ft_utils.c

BONUS_CLIENT = client_bonus.c ft_utils.c
BONUS_SERVER = server_bonus.c ft_utils.c

OBJ_S = $(SRC_SERVER:.c=.o)
OBJ_C = $(SRC_CLIENT:.c=.o)

B_OBJ_S = $(BONUS_SERVER:.c=.o)
B_OBJ_C = $(BONUS_CLIENT:.c=.o)

all: $(NAME_SERVER) $(NAME_CLIENT)

bonus: $(NAME_BONUSC) $(NAME_BONUSS)

$(NAME_CLIENT): $(OBJ_C) $(INCLUDE)
		gcc $(CFLAGS) $(SRC_CLIENT) -o $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_S) $(INCLUDE)
		gcc $(CFLAGS) $(SRC_SERVER) -o $(NAME_SERVER)

$(NAME_BONUSC): $(B_OBJ_C) $(INCLUDE)
		gcc $(CFLAGS) $(B_OBJ_C) -o $(NAME_BONUSC)

$(NAME_BONUSS): $(B_OBJ_S) $(INCLUDE)
		gcc $(CFLAGS) $(B_OBJ_S) -o $(NAME_BONUSS)

clean:
	rm -f $(OBJ_C)
	rm -f $(OBJ_S)
	rm -f $(B_OBJ_C)
	rm -f $(B_OBJ_S)
	@echo "Objets cleaned"

fclean: clean
	rm -f $(NAME_CLIENT)
	rm -f $(NAME_SERVER)
	rm -f $(NAME_BONUSC)
	rm -f $(NAME_BONUSS)
	@echo "executable files cleaned"

re: fclean all

.PHONY: all clean fclean re
