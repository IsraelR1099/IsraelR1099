# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffusalba <ffusalba@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/19 13:03:06 by ffusalba          #+#    #+#              #
#    Updated: 2021/12/19 19:28:22 by ffusalba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rush-02
SRC = rush02_backupSat2042.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
