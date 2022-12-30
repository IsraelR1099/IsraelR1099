# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/30 11:52:04 by irifarac          #+#    #+#              #
#    Updated: 2022/12/30 12:42:25 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colores
RED = \033[0;31m
GREEN = \033[0;32m
RESET = \033[0m

NAME = miniRT
CFLAGS = -Wall -Wextra -Werror -MMD
DEPENDS =$(patsubst %.c, %.d, $(SRC))

#Carpetas
OBJDIR = obj
SRCDIR = ./

#Archivos
SRC = src/main.c

OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

all: $(NAME)

#incluir dependencia
-include $(DEPENDS)
$(NAME): $(OBJ)
	@echo "$(GREEN)Compilando libreria mlx$(RESET)"
	cd mlx && make all
	@echo "$(GREEN)Creando ejecutable $@ 🛠  $(RESET)"
	gcc $(CFLAGS) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@
	@echo "$(GREEN)Compilacion acabada ✅ $@ $(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c include/miniRT.h
	@echo "$(GREEN)Compilando $< de $@ $(RESET)"
	@mkdir -p $(@D)
	gcc $(CFLAGS) -o $@ -c $<

clean:
ifneq ("$(wildcard $(OBJ) $(DEPENDS) $(OBJDIR))", "")
	rm -f $(OBJ) $(DEPENDS)
	rm -rf $(OBJDIR)
	cd mlx && make $@
	@echo "$(GREEN)Objetos borrados 🗑 $(RESET)"
else
	@echo "$(RED)Los objetos no existen, no se borra ❌ $(RESET)"
endif

fclean: clean
ifneq ("$(wildcard $(NAME))", "")
	rm -f $(NAME)
	@echo "$(GREEN)Ejecutables borrados ✅ $(RESET)"
else
	@echo "$(RED)Los ejecutables no existen, no se borra ❌ $(RESET)"
endif

re: fclean all

.PHONY: all clean fclean re
