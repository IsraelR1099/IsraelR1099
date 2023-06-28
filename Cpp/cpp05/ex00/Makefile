# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/14 20:28:25 by irifarac          #+#    #+#              #
#    Updated: 2023/06/28 12:37:49 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[0;31m
GREEN = \033[0;32m
RESET = \033[0m

NAME = Bureaucrat

OBJ_DIR = obj

SRC = Bureaucrat.cpp main.cpp
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)
DEP = $(addsuffix .d, $(basename $(OBJ)))

CPPFLAGS = -Wall -Wextra -Werror -pedantic -std=c++98 -MMD -g

all: $(NAME)

-include $(DEP)
$(NAME): $(OBJ)
	@echo "$(GREEN)Creating binary $(NAME)$(RESET)"
	c++ $(OBJ) $(CPPFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp Makefile Bureaucrat.hpp
	@echo "$(GREEN)Compiling.. $<$(RESET)"
	@mkdir -p $(@D)
	c++ $(CPPFLAGS) -c $< -o $@

clean:
ifneq ("$(wildcard $(OBJ) $(DEP) $(OBJ_DIR))", "")
	rm -rf $(OBJ) $(DEP)
	rm -rf $(OBJ_DIR)
	@echo "$(GREEN)Objetos borrados $(RESET)"
else
	@echo "$(RED)Los objetos no existen, no se borra $(RESET)"
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


