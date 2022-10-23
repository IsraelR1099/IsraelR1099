# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 13:42:29 by irifarac          #+#    #+#              #
#    Updated: 2022/10/23 12:46:43 by dbekic           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colores
RED = \033[0;31m
GREEN = \033[0;32m
RESET = \033[0m

UNAME_S := $(shell uname -s)
NAME = minishell
CFLAGS = -Wall -Werror -Wextra -MMD

#LDFLAGS = /opt/homebrew/opt/readline/lib
#RFLAGS = /opt/homebrew/opt/readline/include
LDFLAGS = /Users/${USER}/homebrew/opt/readline/lib
RFLAGS = /Users/${USER}/homebrew/opt/readline/include

# Folders
OBJDIR = obj
SRCDIR = ./
EXECDIC = srcs/exec

# Files
LIBFT = Libft

SRC = srcs/main/main.c \
	  srcs/parser/ft_utils.c \
	  srcs/parser/ft_build.c \
	  srcs/parser/ft_parser.c \
	  srcs/parser/ft_termination.c \
	  srcs/exec/ft_exec.c    \
	  srcs/parser/ft_prompt_parser.c \
	  srcs/parser/ft_heredoc.c \
	  srcs/parser/ft_builtin_parser.c \
	  srcs/parser/ft_quotes.c \
	  srcs/parser/ft_aux_redir.c \
	  srcs/parser/ft_prompt_expander.c \
	  srcs/parser/ft_error.c \
	  srcs/main/ft_signals.c \
	  srcs/builtins/ft_echo.c    \
	  srcs/builtins/ft_env.c    \
	  srcs/builtins/ft_export.c    \
	  srcs/builtins/ft_pwd.c     \
	  srcs/builtins/ft_unset.c    \
	  srcs/builtins/ft_cd.c    \
	  srcs/builtins/ft_exit.c   \
	  srcs/env/ft_create_elem.c    \
	  srcs/env/ft_expand.c    \
	  srcs/env/ft_find_elem.c    \
	  srcs/env/ft_find_key_value.c    \
	  srcs/env/ft_free_env.c    \
	  srcs/env/ft_init_env.c    \
	  srcs/env/ft_var_name_check.c    \
	  srcs/exec/ft_run_builtin.c    \
	  srcs/exec/ft_find_command.c    \
	  srcs/exec/ft_is_file_or_dir.c    \
	  srcs/exec/ft_execve.c    

OBJ = $(SRC:%.c=$(OBJDIR)/%.o)
# OBJ = $(patsubst %.c, %.o, $(SRC))

DEPENDS = $(patsubst %.c, %.d, $(SRC))

all: makelibs $(NAME)

makelibs:
	@$(MAKE) -C $(LIBFT)

#incluir dependencias
-include $(DEPENDS)
$(NAME): $(OBJ) includes/minishell.h Libft/libft.h Libft/libft.a
	@echo "$(GREEN)Creando ejecutable 🛠 $@ $(RESET)"
	gcc $(CFLAGS) $(OBJ) -LLibft -lft -L$(LDFLAGS) -lreadline -o $@
	@rm -f minishell.d
	@echo "$(GREEN)Compilado ✅ $@ $(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c includes/minishell.h Libft/libft.h
	@echo "$(GREEN)Compilando $< de $@ $(RESET)"
	@mkdir -p $(@D)
	gcc -I$(RFLAGS) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf ./obj
	rm -rf minishell
	@make fclean -C $(LIBFT)

# ifneq ("$(wildcard $(OBJ) $(DEPENDS) $(OBJDIR))", "")
# 	rm -f $(OBJ) $(DEPENDS)
# 	rm -rf $(OBJDIR)
# 	@echo "$(GREEN)Borrando objetos de $(LIBFT)⚠️ $(RESET)"
# 	@make clean -C $(LIBFT)
# 	@echo "$(GREEN)Objetos borrados$(RESET)"
# else
# 	rm Libft/*.d 
# 	@echo "$(RED)Los objetos no existen, no se borra$(RESET)"
# endif

fclean:	clean
ifneq ("$(wildcard $(NAME))", "")
# 	rm -f $(NAME)
	@make fclean -C $(LIBFT)
	@echo "$(GREEN)Ejecutables borrados$(RESET)"
else
	@echo "$(RED)Los ejecutables no existen, no se borra$(RESET)"
endif

re: fclean all

.PHONY: all clean fclean re
