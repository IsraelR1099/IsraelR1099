# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/30 11:52:04 by irifarac          #+#    #+#              #
#    Updated: 2023/01/27 20:56:48 by irifarac         ###   ########.fr        #
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
SRC = 	src/parser/ft_error.c \
		src/parser/ft_utils.c \
		src/parser/ft_check_grammar.c \
		src/parser/get_next_line.c \
		src/parser/get_next_line_utils.c \
		src/parser/ft_parser_ambient.c \
		src/parser/ft_parser_object.c \
		src/parser/ft_utils_obj.c \
		src/parser/ft_build.c \
		src/parser/ft_build_obj.c \
		src/parser/ft_getident.c \
		src/parser/ft_getobj.c \
		src/parser/ft_help_func.c \
		src/parser/ft_arg.c \
		src/ft_init.c \
		src/main.c

OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

all: $(NAME)

#incluir dependencia
-include $(DEPENDS)
$(NAME): $(OBJ)
	@echo "$(GREEN)Compilando libreria mlx$(RESET)"
	#cd MLX42 && make all
	@echo "$(GREEN)Creando ejecutable $@ 🛠  $(RESET)"
	#gcc $(CFLAGS) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@
	gcc $(CFLAGS) $(OBJ) -ldl -lglfw -pthread -lm -o $@
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
