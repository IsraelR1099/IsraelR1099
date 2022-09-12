# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 13:42:29 by irifarac          #+#    #+#              #
#    Updated: 2022/09/12 14:01:44 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colores
RED = \033[0;31m
GREEN = \033[0;32m
RESET = \033[0m

NAME = minishell
CFLAGS = -Wall -Werror -Wextra -MMD

# Folders
OBJDIR = obj
SRCDIR = srcs/parser

# Files
LIBFT = Libft
SRC = $(SRCDIR)/main.c \
	  $(SRCDIR)/ft_utils.c \
	  $(SRCDIR)/ft_build.c \
	  $(SRCDIR)/ft_parser.c \
	  $(SRCDIR)/ft_exec.c

OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
DEPENDS = $(patsubst %.c, %.d, $(SRC))

all: makelibs $(NAME)

makelibs:
	@$(MAKE) -C $(LIBFT)

#incluir dependencias
-include $(DEPENDS)
$(NAME): $(OBJ)
	@echo "$(GREEN)Creando ejecutable 🛠 $@ $(RESET)"
	gcc $(CFLAGS) $(SRC) -LLibft -lft -lreadline -o $@
	@rm -f minishell.d
	@echo "$(GREEN)Compilado ✅ $@ $(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo "$(GREEN)Compilando $< de $@ $(RESET)"
	@mkdir -p $(@D)
	gcc $(CFLAGS) -o $@ -c $<

clean:
ifneq ("$(wildcard $(OBJ) $(DEPENDS) $(OBJDIR))", "")
	rm -f $(OBJ) $(DEPENDS)
	rm -rf $(OBJDIR)
	@echo "$(GREEN)Borrando objetos de $(LIBFT)⚠️ $(RESET)"
	@make clean -C $(LIBFT)
	@echo "$(GREEN)Objetos borrados$(RESET)"
else
	@echo "$(RED)Los objetos no existen, no se borra$(RESET)"
endif

fclean: clean
ifneq ("$(wildcard $(NAME))", "")
	rm -f $(NAME)
	@make fclean -C $(LIBFT)
	@echo "$(GREEN)Ejecutables borrados$(RESET)"
else
	@echo "$(RED)Los ejecutables no existen, no se borra$(RESET)"
endif

re: fclean all

.PHONY: all clean fclean re

