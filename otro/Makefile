SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
 ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
 ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_strdup.c ft_substr.c ft_strjoin.c \
 ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRCSBONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstiter.c ft_lstclear.c

OBJS = ${SRCS:.c=.o}

OBJSBONUS = ${SRCSBONUS:.c=.o}

NAME = libft.a

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o: ${CC} ${CFLAGS} -I libft.h -c $< -o ${<:.c=.o}

all: 		${NAME}

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}
			ranlib ${NAME}

bonus:		${OBJS} ${OBJSBONUS}
			ar rcs ${NAME} ${OBJS} ${OBJSBONUS}
			ranlib ${NAME}
clean: 		
			${RM} ${OBJS} ${OBJSBONUS}

fclean: 	clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all clean fclean re bonus
