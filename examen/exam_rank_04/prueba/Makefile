# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 13:42:29 by irifarac          #+#    #+#              #
#    Updated: 2023/03/08 09:43:17 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colores
RED = \033[0;31m
GREEN = \033[0;32m
RESET = \033[0m

NAME = minishell
CFLAGS = -Wall -Werror -Wextra -MMD -g #-fsanitize=address
LDFLAGS = /Users/${USER}/.brew/opt/readline/lib
RFLAGS = /Users/${USER}/.brew/opt/readline/include

UNAME_S := $(shell uname -s)

# Folders
OBJDIR = obj
SRCDIR = srcs/parser

# Files
LIBFT = Libft
SRC = $(SRCDIR)/main.c \
	  $(SRCDIR)/ft_error.c \
	  $(SRCDIR)/ft_utils.c \
	  $(SRCDIR)/ft_build.c \
	  $(SRCDIR)/ft_builtin_parser.c \
	  $(SRCDIR)/ft_parser.c \
	  $(SRCDIR)/ft_exec.c \
	  $(SRCDIR)/ft_termination.c \
	  $(SRCDIR)/ft_execve.c \
	  $(SRCDIR)/ft_signals.c \
	  $(SRCDIR)/ft_quotes.c \
	  $(SRCDIR)/ft_aux_redir.c \
	  $(SRCDIR)/ft_heredoc.c \
	  $(SRCDIR)/ft_in_quotes.c

OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
DEPENDS = $(patsubst %.c, %.d, $(SRC))

all: makelibs $(NAME)

makelibs:
	@$(MAKE) -C $(LIBFT)

#incluir dependencias
-include $(DEPENDS)
$(NAME): $(OBJ)
	@echo "$(GREEN)Creando ejecutable 🛠 $@ $(RESET)"
ifeq ($(UNAME_S), Linux)
	gcc $(CFLAGS) $(OBJ) -LLibft -lft -lreadline -o $@
else
	gcc $(CFLAGS) $(OBJ) -LLibft -lft -L$(LDFLAGS) -lreadline -o $@
endif
	@rm -f minishell.d
	@echo "$(GREEN)Compilado ✅ $@ $(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo "$(GREEN)Compilando $< de $@ $(RESET)"
	@mkdir -p $(@D)
ifeq ($(UNAME_S), Linux)
	gcc $(CFLAGS) -c $< -o $@
else
	gcc -I$(RFLAGS) $(CFLAGS) -c $< -o $@
endif

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

