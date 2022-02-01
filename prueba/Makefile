# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 13:46:45 by irifarac          #+#    #+#              #
#    Updated: 2022/02/01 13:40:52 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CREATION_LIB = ar -crs
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a
SRC = ft_atoi.c \
	   ft_bzero.c \
	   ft_calloc.c \
	   ft_isalnum.c \
	   ft_isalpha.c \
	   ft_isascii.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_memcpy.c \
	   ft_memmove.c\
	   ft_memset.c \
	   ft_strchr.c \
	   ft_strdup.c \
	   ft_strlcat.c \
	   ft_strlcpy.c \
	   ft_strlen.c \
	   ft_strncmp.c \
	   ft_strnstr.c \
	   ft_strrchr.c \
	   ft_tolower.c \
	   ft_toupper.c \
	   ft_itoa.c \
	   ft_strjoin.c \
	   ft_substr.c \
	   ft_strtrim.c \
	   ft_strmapi.c \
	   ft_striteri.c

OBJ = $(SRC:.c=.o)
INCLUDE = libft.h

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	$(CREATION_LIB) $(NAME) $(OBJ)
	@echo "Compiling"

%.o: %.c
	@echo "Compilando"
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
