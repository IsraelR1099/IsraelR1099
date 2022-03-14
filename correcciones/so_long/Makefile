
NAME = so_long

SRC = main.c getnextline/get_next_line.c getnextline/get_next_line_utils.c maps.c maps_utils_functions.c\
	 maps_init_and_print_functions.c extra_functions.c text.c hero_sprites.c inits.c\
	 inits_images.c show.c hero_moves.c keyboard_inputs.c hero_basic_images.c hero_sprites_images.c exit.c\
	 map_validations.c map_validations2.c mallocs.c mallocs_enemys_bonus.c
SRCSBONUS = main_bonus.c getnextline/get_next_line.c getnextline/get_next_line_utils.c maps_bonus.c maps_utils_functions.c\
	 maps_init_and_print_functions.c extra_functions.c text.c hero_sprites.c inits.c enemys_bonus.c enemy_move_bonus.c\
	 inits_images.c show.c hero_moves.c keyboard_inputs.c hero_basic_images.c hero_sprites_images.c exit_bonus.c\
	 map_validations_bonus.c map_validations2.c mallocs.c mallocs_enemys_bonus.c

OBJ = $(SRC:.c=.o)
OBJSBONUS = ${SRCSBONUS:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
		make -C minilibx
		mv minilibx/libmlx.a .
		gcc -Wall -g -Werror -Wextra -c $(SRC)
		gcc -Wall -g -Werror -Wextra -L. -lmlx -framework OpenGL -framework Appkit $(OBJ) -o $(NAME)

bonus:	${OBJSBONUS}
		make -C minilibx
		mv minilibx/libmlx.a .
		gcc -Wall -g -Werror -Wextra -L. -lmlx -framework OpenGL -framework Appkit $(OBJSBONUS) -o $(NAME)

clean:
		make -C minilibx clean
		rm -rf $(OBJ) $(OBJSBONUS)

fclean: clean
		make -C minilibx clean
		rm -rf $(NAME) 

re : fclean all

.PHONY: all clean fclean re bonus