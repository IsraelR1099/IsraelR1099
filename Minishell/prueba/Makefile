# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 13:42:29 by irifarac          #+#    #+#              #
#    Updated: 2022/09/05 13:54:17 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colores
RED = \033[0;31m
GREEN = \033[0;32m
RESET = \033[0m

NAME = minishell
CFLAGS = -Wall -Werror -Wextra -MMD
SRC = srcs/parser/main.c \
	  srcs/parser/ft_parser.c \
	  srcs/parser/ft_utils.c

OBJ = $(SRC:.c=.o)
DEPENDS = $(patsubst %.c, %.d, $(SRC))

all: $(NAME)

#incluir dependencias
-include $(DEPENDS)
$(NAME): $(OBJ)
	@echo "$(GREEN)Creando ejecutable $@ $(RESET)"
	gcc $(CFLAGS) $(SRC) -lreadline -o $@
	rm -f minishell.d
	@echo "$(GREEN)Compilado $@ $(RESET)"

%.o: %.c
	@echo "$(GREEN)Compilando $< de $@ $(RESET)"
	gcc $(CFLAGS) -o $@ -c $<

clean:
ifneq ("$(wildcard $(OBJ) $(DEPENDS))", "")
	rm -f $(OBJ) $(DEPENDS)
	@echo "$(GREEN)Objetos borrados$(RESET)"
else
	@echo "$(RED)Los objetos no existen, no se borra$(RESET)"
endif

fclean: clean
ifneq ("$(wildcard $(NAME))", "")
	rm -f $(NAME)
	@echo "$(GREEN)Ejecutables borrados$(RESET)"
else
	@echo "$(RED)Los ejecutables no existen, no se borra$(RESET)"
endif

re: fclean all

.PHONY: all clean fclean re

