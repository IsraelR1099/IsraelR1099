# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davidbekic <davidbekic@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 11:51:00 by irifarac          #+#    #+#              #
#    Updated: 2023/11/30 22:08:29 by davidbekic       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[0;31m
GREEN = \033[0;32m
RESET = \033[0m

NAME = ircserv

OBJ_DIR = obj
HEADERS = include/Reply.hpp \
			include/Server.hpp \
			include/Client.hpp \
			include/Channel.hpp

SRC =	./main.cpp \
		src/Reply.cpp \
		src/Server.cpp \
		src/Client.cpp \
		src/commands/pass.cpp \
		src/commands/user.cpp \
		src/commands/privmsg.cpp \
		src/commands/join.cpp \
		src/utilServer.cpp \
		src/Channel.cpp \
		src/commands/nick.cpp \
		src/commands/cap.cpp \
		src/commands/mode.cpp \
		src/commands/topic.cpp \
		src/commands/invite.cpp \
		src/commands/kick.cpp \
		src/commands/part.cpp \
		src/commands/quit.cpp \
		src/commands/ping.cpp 

OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)
DEP = $(addsuffix .d, $(basename $(OBJ)))

CPPFLAGS = -Wall -Wextra -Werror -pedantic -std=c++98 -MMD -g

all: $(NAME)

-include $(DEP)
$(NAME): $(OBJ)
	@echo "$(GREEN)Creating binary $(NAME)$(RESET)"
	c++ $(OBJ) $(CPPFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp Makefile $(HEADERS)
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