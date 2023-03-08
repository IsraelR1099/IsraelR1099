# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/30 11:52:04 by irifarac          #+#    #+#              #
#    Updated: 2023/03/08 10:43:08 by irifarac         ###   ########.fr        #
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
INCLUDE = $(OBJ) include/miniRT.h src/parser/libparser.a src/cameras/libcameras.a \
		  src/world/libworld.a src/maths/libmaths.a src/window/libwindow.a \
		  include/miniRT.h
LINK = -L./src/parser -lparser -L/mlx/ -lmlx -L./src/cameras/ -lcameras \
	   -L./src/world/ -lworld -L./src/maths/ -lmaths \
	   -L./src/window/ -lwindow
CFLAGS = -Wall -Wextra -Werror -MMD -lmlx -lbmp -lm -lbsd -lX11 -lXext -g
MACFLAGS = -Wall -Wextra -Werror -MMD -g -O0
UNAME = $(shell uname -s)
DEPENDS =$(patsubst %.c, %.d, $(SRC))

#Carpetas
OBJDIR = obj
SRCDIR = ./
DIRMLX = ./mlx/
DIRBMP = ./libbmp/
#DIRINC = ./include/
DIRINC = /usr/include
PARSER = src/parser
MATHS = src/maths
WINDOW = src/window
WORLD = src/world
CAMERA = src/cameras

#Archivos
SRC =	src/main.c \
		src/render/ft_init.c \
		src/render/ft_render.c \
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
	@$(MAKE) -C $(MATHS)
	@$(MAKE) -C $(CAMERA)
	@$(MAKE) -C $(WORLD)
	@$(MAKE) -C $(WINDOW)

#incluir dependencia
-include $(DEPENDS)
$(NAME): $(INCLUDE)
	@echo "$(GREEN)Compilando libreria mlx$(RESET)"
	cd mlx && make all
	cd libbmp && make all
	@echo "$(GREEN)Creando ejecutable $@ 🛠  $(RESET)"
ifeq ($(UNAME), Linux)
	gcc $(OBJ) -L./src/parser -lparser -L$(DIRMLX) -lmlx -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)
else
	gcc $(CFLAGS) $(OBJ) $(LINK) -Lmxl -lmlx -framework OpenGL -framework AppKit -o $@
endif
	@echo "$(GREEN)Compilacion acabada ✅ $@ $(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo "$(GREEN)Compilando $< de $@ $(RESET)"
	@mkdir -p $(@D)
ifeq ($(UNAME), Linux)
	gcc $(CFLAGS) -I$(DIRINC) -I$(DIRMLX) -O3 -c $< -o $@
else
	gcc $(MACFLAGS) -o $@ -c $<
endif

clean:
ifneq ("$(wildcard $(OBJ) $(DEPENDS) $(OBJDIR))", "")
	rm -f $(OBJ) $(DEPENDS)
	rm -rf $(OBJDIR)
	@make clean -C src/parser/
	@make clean -C src/world/
	@make clean -C src/cameras/
	cd mlx && make $@
	@echo "$(GREEN)Objetos borrados 🗑 $(RESET)"
else
	@echo "$(RED)Los objetos no existen, no se borra ❌ $(RESET)"
endif

fclean: clean
ifneq ("$(wildcard $(NAME))", "")
	cd src/parser && make fclean
	cd src/world  && make fclean
	cd src/cameras && make fclean
	rm -f $(NAME)
	@echo "$(GREEN)Ejecutables borrados ✅ $(RESET)"
else
	@echo "$(RED)Los ejecutables no existen, no se borra ❌ $(RESET)"
endif

re: fclean all

.PHONY: all clean fclean re
