# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 02:38:37 by mporras-          #+#    #+#              #
#    Updated: 2022/03/06 01:21:46 by mporras-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		 =	checker
LIB 		 =	libft.a
LIB_DIR 	 =	../libft/
SRC_DIR		 =	srcs
SRCS_FILES	 =	ch_actions.c \
				ch_clear_stacks.c \
				ch_do_actions.c \
				ch_loading_checks.c \
				ch_loading_utils.c \
				ch_process_inputs.c \
				ch_utils.c \
				get_next_line.c \
				get_next_line_utils.c \
				ps_checker.c
SRCS 		 =	$(addprefix $(SRC_DIR)/,$(SRCS_FILES))
OBJS		 =	$(SRCS_FILES:.c=.o)
CC			 =	gcc
RM			 = 	rm	-f
CFLAGS		 =	-Wall -Wextra -Werror
INCLUDES	 =	-Iinc/checker.h

all: $(NAME)
 
$(NAME): $(OBJS) $(LIB_DIR)$(LIB)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB_DIR)$(LIB)

	mv $(NAME) ../

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c -D BUFFER_SIZE=100 $(SRCS) $(INCLUDES)

$(LIB_DIR)$(LIB):
	$(MAKE) bonus -C $(LIB_DIR)

clean:
	$(MAKE) -C $(LIB_DIR) clean
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) ../$(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re
