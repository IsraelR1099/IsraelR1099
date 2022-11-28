# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 13:42:29 by irifarac          #+#    #+#              #
#    Updated: 2022/11/28 13:25:06 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colores
RED = \033[0;31m
GREEN = \033[0;32m
RESET = \033[0m

NAME = philo
CFLAGS = -Wall -Werror -Wextra -MMD

# Folders
OBJDIR = obj
SRCDIR = ./

# Files
SRC = src/ft_error.c \
	  src/ft_utils.c \
	  src/main.c

OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

DEPENDS = $(patsubst %.c, %.d, $(SRC))

all: $(NAME)

#incluir dependencias
-include $(DEPENDS)
$(NAME): $(OBJ) include/philosopher.h
	@echo "$(GREEN)Creando ejecutable 🛠 $@ $(RESET)"
	gcc $(CFLAGS) $(OBJ) -o $@
	@rm -f minishell.d
	@echo "$(GREEN)Compilado ✅ $@ $(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c include/philosopher.h
	@echo "$(GREEN)Compilando $< de $@ $(RESET)"
	@mkdir -p $(@D)
	gcc $(CFLAGS) -o $@ -c $<

clean:
ifneq ("$(wildcard $(OBJ) $(DEPENDS) $(OBJDIR))", "")
	rm -f $(OBJ) $(DEPENDS)
	rm -rf $(OBJDIR)
	@echo "$(GREEN)Objetos borrados$(RESET)"
else
	@echo "$(RED)Los objetos no existen, no se borra$(RESET)"
endif

fclean:	clean
ifneq ("$(wildcard $(NAME))", "")
	rm -f $(NAME)
	@echo "$(GREEN)Ejecutables borrados$(RESET)"
else
	@echo "$(RED)Los ejecutables no existen, no se borra$(RESET)"
endif

re: fclean all

.PHONY: all clean fclean re
