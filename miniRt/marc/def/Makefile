# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 09:40:37 by irifarac          #+#    #+#              #
#    Updated: 2023/05/10 12:51:33 by irifarac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colours

RED = \033[0;31m
GREEN = \033[0;32m
RESET = \033[0m

# Binary

NAME = miniRT

# Directories

SRC_DIR = ./
INCLUDE_DIR = include
OBJ_DIR = obj

# Files

LIBS = src/cameras/libcameras.a
LIBS += src/geometricobj/libgeometricobj.a
LIBS += src/maths/libmath.a
LIBS += src/parser/libparser.a
LIBS += src/samplers/libsampler.a
LIBS += src/tracers/libtracers.a
LIBS += src/utilities/libshade.a
LIBS += src/lights/liblights.a
LIBS += src/materials/libmaterials.a
LIBS += src/brdf/libbrdf.a
LIBS += src/color/libcolor.a
LIBS += src/window/libwindow.a
LIBS += src/world/libworld.a
LIBS_HEADER = -I./mlx
LIBS_HEADER += -I./src/window/
LIBS_HEADER += -I./src/world
LIBS_HEADER += -I./src/samplers/
LIBS_HEADER += -I./src/cameras/
LIBS_HEADER += -I./src/tracers/
LIBS_HEADER += -I./src/materials/
LIBS_HEADER += -I./src/utilities/
LIBS_HEADER += -I./src/lights/
LIBS_HEADER += -I./src/brdf/
LIBS_HEADER += -I./src/color/
LIBS_HEADER += -I./src/geometricobj/
LIBS_HEADER += -I./src/maths/
LIBS_HEADER += -I./src/parser/
LDFLAGS = -L./mlx
LDFLAGS += -L./src/window
LDFLAGS += -L./src/world
LDFLAGS += -L./src/samplers
LDFLAGS += -L./src/cameras
LDFLAGS += -L./src/tracers
LDFLAGS += -L./src/materials
LDFLAGS += -L./src/utilities
LDFLAGS += -L./src/lights
LDFLAGS += -L./src/brdf
LDFLAGS += -L./src/color
LDFLAGS += -L./src/geometricobj
LDFLAGS += -L./src/maths
LDFLAGS += -L./src/parser
LIB = -lwindow
LIB += -lworld
LIB += -lsampler
LIB += -lcameras
LIB += -ltracers
LIB += -lmaterials
LIB += -lshade
LIB += -llights
LIB += -lbrdf
LIB += -lcolor
LIB += -lgeometricobj
LIB += -lmath
LIB += -lparser
LIB += -lmlx

INC = $(LIBS_HEADER) -I./$(INCLUDE_DIR)

SRC = src/main.c \
		src/render/ft_init.c \
		src/render/ft_free.c \
		src/render/ft_render.c \
		src/utilities/ft_find.c \
		src/utilities/ft_handler.c

#OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:%.c=o))
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
DEP = $(addsuffix .d, $(basename $(OBJ)))

# Compilation

CFLAGS = -Wall -Werror -Wextra -MMD -MP -O0 $(INC)
DFLAGS = -g

# Rules


all: makelibs $(NAME)

makelibs:
	$(MAKE) -C ./mlx
	$(MAKE) -C src/parser
	$(MAKE) -C src/cameras
	$(MAKE) -C src/maths
	$(MAKE) -C src/window
	$(MAKE) -C src/world
	$(MAKE) -C src/samplers
	$(MAKE) -C src/tracers
	$(MAKE) -C src/materials
	$(MAKE) -C src/lights
	$(MAKE) -C src/brdf
	$(MAKE) -C src/color
	$(MAKE) -C src/geometricobj
	$(MAKE) -C src/utilities

-include $(DEP)
$(NAME): $(OBJ) $(LIBS)
	@echo "$(GREEN)Creating binary $(NAME) $(RESET)"
	gcc $(OBJ) $(LDFLAGS) $(LIB) -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(GREEN)Compilation finished ✅ $@ $(RESET)"


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	@mkdir -p $(@D)
	gcc $(DFLAGS) $(CFLAGS) -O3 -c $< -o $@
	@echo "$(GREEN)Compiling.. 🛠  $< $(RESET)"

clean:
ifneq ("$(wildcard $(OBJ) $(DEPENDS) $(OBJ_DIR))", "")
	rm -f $(OBJ) $(DEPENDS)
	rm -rf $(OBJ_DIR)
	@make clean -C src/parser/
	@make clean -C src/world/
	@make clean -C src/cameras
	@make clean -C src/geometricobj/
	@make clean -C src/maths/
	@make clean -C src/materials/
	@make clean -C src/samplers/
	@make clean -C src/tracers/
	@make clean -C src/utilities/
	@make clean -C src/brdf/
	@make clean -C src/window/
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
	cd src/brdf && make fclean
	cd src/geometricobj && make fclean
	cd src/materials && make fclean
	cd src/maths && make fclean
	cd src/samplers && make fclean
	cd src/tracers && make fclean
	cd src/utilities && make fclean
	cd src/window && make fclean
	rm -f $(NAME)
	@echo "$(GREEN)Ejecutables borrados ✅ $(RESET)"
else
	@echo "$(RED)Los ejecutables no existen, no se borra ❌ $(RESET)"
endif

re: fclean all

.PHONY: all clean fclean re
