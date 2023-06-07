# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 10:07:31 by irifarac          #+#    #+#              #
#    Updated: 2023/05/12 12:31:31 by msoler-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colores

RED = \033[0;31m
GREEN = \033[0;32m
RED = \033[0m

NAME = liblights.a
CFLAGS = -Wall -Wextra -Werror -MMD -g -O0
CREATION_LIB = ar -rcs
DEPENDS = $(patsubst %.c, %.d, $(SRC))

#Carpetas
OBJDIR = obj
SRCDIR = ./
SRC = ft_lights.c \
		ft_sphere.c \
		ft_hit_shadow.c \
		ft_plane.c \
		ft_cylon.c \
		ft_cylon_utilities.c \
		ft_cylon_utilities2.c \
		ft_utils.c \
		ft_disk.c
OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

all: $(NAME)

#dependencias
-include $(DEPENDS)
$(NAME): $(OBJ)
	@echo "$(GREEN)Compilando parser$(RESET)"
	$(CREATION_LIB) $(NAME) $(OBJ)
	@echo "$(GREEN)Compilado $@ $(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c lights.h
	@echo "$(GREEN)Compilando $< de $@ $(RESET)"
	@mkdir -p $(@D)
	gcc $(CFLAGS) -o $@ -c $<

clean:
ifneq ("$(wildcard $(OBJ) $(DEPENDS) $(OBJDIR))", "")
	rm -f $(OBJ) $(DEPENDS)
	rm -rf $(OBJDIR)
	@echo "$(GREEN)Objetos borrados $(RESET)"
else
	@echo "$(RED)Los objetos de $(NAME) no existen $(RESET)"
endif

fclean: clean
ifneq ("$(wildcard $(NAME))", "")
	rm -f $(NAME)
	@echo "$(GREEN)Ejecutable de $(NAME) borrado$(RESET)"
else
	@echo "$(RED)El ejecutable de $(NAME) no existe$(RESET)"
endif

re: fclean all

.PHONY: all clean fclean re
