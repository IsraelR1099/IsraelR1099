# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 13:14:50 by irifarac          #+#    #+#              #
#    Updated: 2022/07/20 12:11:35 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colores
RED = \033[0;31m
GREEN = \033[0;32m
RESET = \033[0m

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror -MMD
SRC = src/ft_errors.c \
	  src/main.c \
	  src/ft_utils.c \
	  src/ft_actions.c \
	  src/ft_ways_sort.c \
	  src/ft_sort.c \
	  src/ft_find.c \
	  src/ft_rules.c \
	  src/ft_rules_b.c \
	  src/ft_rules_general.c \
	  src/ft_utils_more.c \
	  src/ft_utils_more2.c \
	  src/ft_utils_more3.c \
	  src/ft_do_stack.c \
	  src/ft_conditions.c \
	  src/ft_conditions2.c \
	  src/ft_phase.c \
	  src/ft_find_best.c

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
ifneq ("$(wildcard $(OBJ) $(DEPENDS))", "")
	rm -f $(OBJ) $(DEPENDS)
	@make clean -C $(LIBFT)
	@echo "$(GREEN)Objetos borrados$(RESET)"
else
	@echo "$(RED)Objetos no existen, no se borra$(RESET)"
endif

fclean: clean
ifneq ("$(wildcard $(NAME))", "")
	cd Libft && make fclean
	rm -f $(NAME)
	@echo "$(GREEN)Ejecutable borrado$(RESET)"
else
	@echo "$(RED)El ejecutable no existe$(RESET)"
endif

re: fclean all

.PHONY: all clean fclean re
