# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student42.barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/14 20:28:25 by irifarac          #+#    #+#              #
#    Updated: 2023/05/15 13:48:11 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[0;31m
GREEN = \033[0;32m
RESET = \033[0m

NAME = agenda

OBJ_DIR = obj

SRC = main.cpp PhoneBook.cpp
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
DEP = $(addsuffix .d, $(basename $(OBJ)))

CPPFLAGS = -Wall -Wextra -Werror -pedantic -MMD -g

all: $(NAME)

-include $(DEP)
$(NAME): $(OBJ)
	@echo "$(GREEN)Creating binary $(NAME)$(RESET)"
	c++ $(OBJ) $(CPPFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c Makefile PhoneBook.hpp
	@echo "$(GREEN)Compiling.. $<$(RESET)"
	c++ $(CPPFLAGS) -c $< -o $@

clean:
ifneq ("$(wildcard $(OBJ) $(DEP) $(OBJ_DIR))", "")
	rm -rf $(OBJ) $(DEP)
	rm -rf $(OBJ_DIR)
	@echo "$(GREEN)Objetos borrados $(RESET)"
else
	@echo "$(RED)Los objetos no existen, no se borra $(RESET)"
endif


