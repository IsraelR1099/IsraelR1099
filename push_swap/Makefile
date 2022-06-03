# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 13:14:50 by irifarac          #+#    #+#              #
#    Updated: 2022/06/03 13:50:42 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colores
RED = \033[0;31m
GREEN = \033[0;32m
RESET = \033[0m

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror -MMD
SRC = src/ft_errors.c \
	  src/main.c

OBJ = $(SRC:.c=.o)
DEPENDS = $(patsubst %.c, %.d, $(SRC))
LIBFT = libft

all: makelibs $(NAME) 

makelibs:
	@$(MAKE) -C $(LIBFT)

#incluir la dependencia a Makefile
-include $(DEPENDS)
$(NAME): $(OBJ) Libft/libft.a
	@echo "$(GREEN)Creando ejecutable $@ $(RESET)"
	gcc $(CFLAGS) $(SRC) -LLibft -lft -o $@
	rm -f push_swap.d
	@echo "$(GREEN)Compilado $@ $(RESET)"

%.o: %.c
	@echo "$(GREEN)Compilando $< de $@ $(RESET)"
	gcc $(CFLAGS) -o $@ -c $<



clean:
	rm -f $(OBJ) $(DEPENDS)
	@make clean -C $(LIBFT)
	@echo "Objetos borrados"

fclean: clean
	cd Libft && make fclean
	rm -f $(NAME)
	@echo "Ejecutable borrado"

re: fclean all

.PHONY: all clean fclean re
