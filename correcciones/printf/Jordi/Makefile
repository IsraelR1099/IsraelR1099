LIBFT_PATH = libft/

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_printf_utils.c\
		   	ft_flag1.c ft_flag2.c\
		   	ft_printf_type.c\
			ft_printf_p_type1.c ft_printf_p_type2.c ft_printf_p_type3.c 
SRC_BONUS = ft_printf_bonus.c ft_printf_utils_bonus.c\
		   	ft_flag1_bonus.c ft_flag2_bonus.c\
		   	ft_printf_type_bonus.c\
			ft_printf_p_type1_bonus.c ft_printf_p_type2_bonus.c ft_printf_p_type3_bonus.c 
OBJS := $(SRC:.c=.o)
OBJS_BONUS := $(SRC_BONUS:.c=.o)

RM 	= rm -f

all: $(NAME)

$(NAME):  mandatory
	 
comun:  
	@$(MAKE) re -s -C $(LIBFT_PATH)
	@mv $(LIBFT_PATH)libft.a ./$(NAME)

mandatory: comun
	@$(CC) $(CFLAGS) -I $(LIBFT_PATH) -c $(SRC) 
	@ar rcs $(NAME) $(OBJS) 		

bonus: comun
	@$(CC) $(CFLAGS) -I $(LIBFT_PATH) -c $(SRC_BONUS)
	@ar rcs $(NAME) $(OBJS_BONUS) 		

clean:
	@$(MAKE) clean -s -C $(LIBFT_PATH)
	@$(RM) $(OBJS)
	@$(RM) $(OBJS_BONUS) 	

fclean: clean
	@$(MAKE) fclean -s -C $(LIBFT_PATH)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
