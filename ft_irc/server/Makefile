# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 11:51:00 by irifarac          #+#    #+#              #
#    Updated: 2023/10/26 20:35:04 by israel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[0;31m
GREEN = \033[0;32m
RESET = \033[0m

NAME = ircserv

OBJ_DIR = obj

SRC = srcs/main.cpp \
	  srcs/server.cpp \
	  srcs/Client.cpp \
	  srcs/commands/pass.cpp \
	  srcs/utilServer.cpp
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)
DEP = $(addsuffix .d, $(basename $(OBJ)))

CPPFLAGS = -Wall -Wextra -Werror -pedantic -std=c++98 -MMD -g

all: $(NAME)

-include $(DEP)
$(NAME): $(OBJ)
	@echo "$(GREEN)Creating binary $(NAME)$(RESET)"
	c++ $(OBJ) $(CPPFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp Makefile include/Server.hpp include/Client.hpp
	@echo "$(GREEN)Compiling... $(RESET)"
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
endif

re: fclean all

.PHONY: all clean fclean re
