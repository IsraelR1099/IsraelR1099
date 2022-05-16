# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 09:34:40 by irifarac          #+#    #+#              #
#    Updated: 2022/05/13 13:48:53 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
FT_PRINTF = ft_printf
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRC = server.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(FT_PRINTF)
	@cp ft_printf/libftprintf.a .
	@mv libftprintf.a $(NAME)
	@$(AR) $(NAME) $(OBJ)
	@echo "ft_printf compiled"

.c.o:
	@echo "Compiling"
	gcc $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ)
	@make clean -C $(FT_PRINTF)
	@echo "ft_printf objets cleaned"

fclean: clean
	rm -f $(NAME)
	rm -f $(FT_PRINTF)/libftprintf.a
	@echo "executable files cleaned"

re: fclean all

.PHONY: all clean fclean re

