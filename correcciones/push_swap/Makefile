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

NAME		 =	push_swap
LIB 		 =	libft.a
LIB_DIR 	 =	libft/
SRC_DIR		 =	srcs
SRCS_FILES	 =	ps_actions.c \
				ps_candidates_to_pull.c \
				ps_cases_solve.c \
				ps_clear_stacks.c \
				ps_check_solve.c \
				ps_do_actions.c \
				ps_find_cuts.c \
				ps_loading_checks.c \
			  	ps_loading_utils.c \
				ps_nodes_get.c \
				ps_presort.c \
			  	ps_small_cases.c \
			  	ps_solver_utils.c \
				ps_spin_sort.c \
			  	ps_sub_stacks.c \
				ps_utils.c \
				push_swap.c
SRCS 		 =	$(addprefix $(SRC_DIR)/,$(SRCS_FILES))
OBJS		 =	$(SRCS_FILES:.c=.o)
CC			 =	gcc
RM			 = 	rm	-f
CFLAGS		 =	-Wall -Wextra -Werror
INCLUDES	 =	-Iinc/push_swap.h

all: $(NAME)
 
$(NAME): $(OBJS) $(LIB_DIR)$(LIB)
	$(CC) $(CFLAGS) -g -o $(NAME) $(OBJS) $(LIB_DIR)$(LIB)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS) $(INCLUDES)

$(LIB_DIR)$(LIB):
	$(MAKE) -C $(LIB_DIR)

clean:
	$(MAKE) -C $(LIB_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIB_DIR) fclean
	$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re push_swap
