# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 13:46:45 by irifarac          #+#    #+#              #
#    Updated: 2022/06/02 12:17:03 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colores
RED = \033[0;31m
GREEN = \033[0;32m
RESET = \033[0m

NAME = libft.a
CFLAGS = -Wall -Werror -Wextra -MMD
SRC = $(wildcard *.c)
BONUS_SRC = $(wildcard Bonus/*.c)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
OBJ = $(SRC:.c=.o)
CREATION_LIB = ar -rcs
DEPENDS = $(patsubst %.c, %.d, $(SRC))
	
all: $(NAME)

-include $(DEPENDS)
$(NAME): $(OBJ)
	@echo "$(GREEN)Compilando libreria de Libft$(RESET)"
	$(CREATION_LIB) $(NAME) $(OBJ)
	@echo "$(GREEN)Compilado$(RESET)"

%.o: %.c
	@echo "$(GREEN)Compilando $< de Libft$(RESET)"
	gcc $(CFLAGS) -o $@ -c $<

bonus : $(NAME) $(BONUS_OBJ)
	$(CREATION_LIB) $(NAME) $(BONUS_OBJ)
	@echo "Compilando bonus"

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re .c.o bonus
