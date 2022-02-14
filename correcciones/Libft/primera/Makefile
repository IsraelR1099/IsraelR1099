# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    by: cteixido <cteixido@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 12:31:20 by cteixido          #+#    #+#              #
#    Updated: 2022/02/09 11:52:17 by cteixido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CF = -Wall -Werror -Wextra
LIB = ar -rcs
RM = rm -f
FT = ft_bzero.c ft_isascii.c ft_memcpy.c ft_strlen.c \
	 ft_isalnum.c ft_isdigit.c ft_memset.c ft_tolower.c \
	 ft_isalpha.c ft_isprint.c ft_strlcpy.c ft_toupper.c \
	 ft_memmove.c ft_memcmp.c ft_strchr.c ft_strrchr.c \
	 ft_strlcat.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
	 ft_strrchr.c ft_memchr.c ft_strnstr.c ft_atoi.c \
	 ft_calloc.c ft_strdup.c ft_putchar_fd.c ft_putstr_fd.c \
	 ft_putendl_fd.c ft_putnbr_fd.c ft_substr.c ft_strjoin.c \
     ft_striteri.c ft_strtrim.c ft_strmapi.c ft_itoa.c ft_split.c

BN = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	 ft_lstdelone.c ft_lstiter.c ft_lstadd_back.c ft_lstclear.c \
	 ft_lstmap.c

OBJ = $(FT:.c=.o)

OBJB = $(BN:.c=.o)

%.o: %.c
		@$(CC) $(CF) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
		$(LIB) $(NAME) $(OBJ)
		@echo "$(NAME) created"	

clean:
		$(RM) $(OBJ) $(OBJB)
		@echo "OBJ deleted"

fclean: clean 
		$(RM) $(NAME)
		@echo "OBJ deleted"


bonus:	
		$(CC) $(CF) -c $(BN)
		$(LIB) $(NAME) *.o

re:		fclean all

.PHONY: all clean fclean re
