# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 13:46:45 by irifarac          #+#    #+#              #
#    Updated: 2022/10/19 18:14:40 by dbekic           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colores
RED = \033[0;31m
GREEN = \033[0;32m
RESET = \033[0m

NAME = libft.a
CFLAGS = -Wall -Werror -Wextra -MMD
SRC =	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_init_zero.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_strjoin.c \
		ft_printf.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c  \
		ft_strncmp.c \
		ft_strchr.c \
		ft_strcmp.c \
		ft_strdup.c  \
		ft_striteri.c \
		ft_tolower.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strchrnul.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_toupper.c 
	
OBJ = $(SRC:.c=.o)
CREATION_LIB = ar -rcs
DEPENDS = $(patsubst %.c, %.d, $(SRC))

all: $(NAME)

-include $(DEPENDS)
$(NAME): $(OBJ)
	@echo "$(GREEN)Compilando libreria de Libft$(RESET)"
	$(CREATION_LIB) $(NAME) $(OBJ)
	@echo "$(GREEN)Compilado$(RESET)"

%.o: %.c
	@echo "$(GREEN)Compilando $< de Libft$(RESET)"
	gcc $(CFLAGS) -o $@ -c $<

clean:
ifneq ("$(wildcard $(OBJ))", "")
	rm -f $(OBJ) $(DEPENDS)
	rm -f libft.d
else
	@echo "$(RED)Objetos Libft no existen, no se borra$(RESET)"
endif

fclean: clean
ifneq ("$(wildcard $(NAME))", "")
	rm -f $(NAME)
	@echo "$(GREEN)Ejecutable borrado$(RESET)"
else
	@echo "$(RED)EL ejecutable de Libft no existe$(RESET)"
endif

re: fclean all

.PHONY: all clean fclean re .c.o
