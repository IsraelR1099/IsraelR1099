# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/30 11:52:04 by irifarac          #+#    #+#              #
#    Updated: 2023/01/27 20:56:48 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colores
RED = \033[0;31m
GREEN = \033[0;32m
RESET = \033[0m

NAME = miniRT
NAMELFT = libft.a
NAMEMLX = libmlx.a
NAMEBMP = libbmp.a
CFLAGS = -Wall -Wextra -Werror -MMD -lmlx -lbmp -lm -lbsd -lX11 -lXext -g
DEPENDS =$(patsubst %.c, %.d, $(SRC))

#Carpetas
OBJDIR = obj
SRCDIR = ./
DIRMLX = ./mlx/
DIRBMP = ./libbmp/
#DIRINC = ./include/
DIRINC = /usr/include
PARSER = src/parser

#Archivos
SRC =	src/main.c \
		src/render/ft_init.c \
		src/render/ft_render.c \
		src/window/ft_my_mlx_pxput.c
		#src/ft_init.c \
		#src/ft_set_frustrum.c \
		#src/ft_color.c \
		#src/ft_generate.c \
		#src/ft_utils_generate.c \
		#src/maths/ft_vector_operation.c \
		#src/ft_intersects.c \
		#src/ft_check_obj.c \
		#src/ft_intersects_plane.c \
		#src/ft_intersects_sphere.c \
		#src/viewspace/ft_ortographic_view.c \
		#src/ft_find.c \
		#src/viewspace/ft_viewSpace.c \
		#src/viewspace/ft_translation.c \
		#src/viewspace/ft_perspective.c \
		#src/transform/ft_obj_transform.c \
		#src/transform/ft_pixel_to_world.c \

OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

all: makelibs $(NAME)

makelibs:
	@$(MAKE) -C $(PARSER)

#incluir dependencia
-include $(DEPENDS)
$(NAME): $(OBJ) include/miniRT.h src/parser/libparser.a
	@echo "$(GREEN)Compilando libreria mlx$(RESET)"
	cd mlx && make all
	cd libbmp && make all
	@echo "$(GREEN)Creando ejecutable $@ 🛠  $(RESET)"
	#gcc $(CFLAGS) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@
#	gcc $(CFLAGS) $(OBJ) -ldl -lglfw -pthread -lm -o $@
#	gcc -o $(NAME) -I$(DIRINC) -I$(DIRMLX) $(OBJ) -L$(DIRMLX) -L$(DIRBMP) $(CFLAGS)	
	gcc $(OBJ) -L./src/parser -lparser -L$(DIRMLX) -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)
	@echo "$(GREEN)Compilacion acabada ✅ $@ $(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo "$(GREEN)Compilando $< de $@ $(RESET)"
	@mkdir -p $(@D)
#	gcc $(CFLAGS) -o $@ -c $<
#	gcc $(CFLAGS) -c -I$(DIRINC) -I$(DIRMLX) $< -o $(<:.c=.o)
	gcc $(CFLAGS) -I$(DIRINC) -I$(DIRMLX) -O3 -c $< -o $@


clean:
ifneq ("$(wildcard $(OBJ) $(DEPENDS) $(OBJDIR))", "")
	rm -f $(OBJ) $(DEPENDS)
	rm -rf $(OBJDIR)
	@make clean -C src/parser/
	cd mlx && make $@
	@echo "$(GREEN)Objetos borrados 🗑 $(RESET)"
else
	@echo "$(RED)Los objetos no existen, no se borra ❌ $(RESET)"
endif

fclean: clean
ifneq ("$(wildcard $(NAME))", "")
	cd src/parser && make fclean
	rm -f $(NAME)
	@echo "$(GREEN)Ejecutables borrados ✅ $(RESET)"
else
	@echo "$(RED)Los ejecutables no existen, no se borra ❌ $(RESET)"
endif

re: fclean all

.PHONY: all clean fclean re
