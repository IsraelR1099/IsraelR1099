# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 09:34:40 by irifarac          #+#    #+#              #
#    Updated: 2022/03/28 14:22:38 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRC = src/ft_printf.c \
	src/ft_printf_utils.c \
	src/ft_printf_string.c \
	src/ft_printf_number.c \
	src/ft_printf_ptr.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	@$(AR) $(NAME) $(OBJ)
	@echo "ft_printf compiled"

.c.o:
	@echo "Compiling"
	gcc $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ)
	@make clean -C $(LIBFT)
	@echo "ft_printf objets cleaned"

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)/libft.a
	@echo "executable files cleaned"

re: fclean all

.PHONY: all clean fclean re

