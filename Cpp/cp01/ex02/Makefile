# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 12:40:41 by irifarac          #+#    #+#              #
#    Updated: 2023/05/25 20:53:13 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[0;31m
GREEN = \033[0;32m
RESET = \033[0m

NAME = brain

SRC = main.cpp
OBJ = $(SRC:%.cpp=%.o)

CPPFLAGS = -Wall -Werror -Wextra -pedantic -std=c++98 -g


all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN) Creating binary $(NAME) $(RESET)"
	@c++ $(OBJ) -o $(NAME)
	@echo "$(GREEN) Compilation finished ✅ $@ $(RESET)"

%.o: %.cpp Makefile
	c++ $(CPPFLAGS) -c $< -o $@
	@echo "$(GREEN) Compiling.. 🛠 $< $(RESET)"

clean:
ifneq ("$(wildcard $(OBJ))", "")
	rm -f $(OBJ)
	@echo "$(GREEN)Objetos borados $(RESET)"
else
	@echo "$(RED)Los objetos no existen, no se borra ❌ $(RESET)"
endif

fclean: clean
ifneq ("$(wildcard $(NAME))", "")
	rm -f $(NAME)
	@echo "$(GREEN)Ejecutable borrado ✅ $(RESET)"
else
	@echo "$(RED)El ejecutable no existe, no se borra ❌ $(RESET)"
endif

re: fclean all

.PHONY: all clean fclean re
