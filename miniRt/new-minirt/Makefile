RED = \033[0;31m
GREEN = \033[0;32m
RESET = \033[0m

#Name
NAME = miniRT

# directories
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
LIBS += src/window/libwindow.a
LIBS += src/world/libworld.a
LIBS_HEADER = -I./mlx
LIBS_HEADER += -I./src/window/
LIBS_HEADER += -I./src/world
LIBS_HEADER += -I./src/samplers/
LIBS_HEADER += -I./src/cameras/
LIBS_HEADER += -I./src/tracers/
LIBS_HEADER += -I./src/utilities/
LIBS_HEADER += -I./src/geometricobj/
LIBS_HEADER += -I./src/maths/
LIBS_HEADER += -I./src/parser/
LDFLAGS = -L./mlx
LDFLAGS += -L./libbmp
LDFLAGS += -L/usr/lib
LDFLAGS += -L./src/window
LDFLAGS += -L./src/world
LDFLAGS += -L./src/samplers
LDFLAGS += -L./src/cameras
LDFLAGS += -L./src/tracers
LDFLAGS += -L./src/utilities
LDFLAGS += -L./src/geometricobj
LDFLAGS += -L./src/maths
LDFLAGS += -L./src/parser
LIB = -lwindow
LIB += -lworld
LIB += -lsampler
LIB += -lcameras
LIB += -ltracers
LIB += -lshade
LIB += -lgeometricobj
LIB += -lmath
LIB += -lparser
LIB += -lmlx -lbmp -lm -lz -lbsd -lX11 -lXext

INC = $(LIBS_HEADER) -I./$(INCLUDE_DIR)

SRC = src/main.c \
		src/render/ft_init.c \
		src/render/ft_render.c \
		src/utilities/ft_find.c

#OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:%.c=o))
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
DEP = $(addsuffix .d, $(basename $(OBJ)))

# Compilation

CFLAGS = -Wall -Werror -Wextra -MMD -MP $(INC)
DFLAGS = -g

# Rules


all: makelibs $(NAME)

makelibs:
	$(MAKE) -C ./mlx
	$(MAKE) -C ./libbmp
	$(MAKE) -C src/parser
	$(MAKE) -C src/cameras
	$(MAKE) -C src/maths
	$(MAKE) -C src/window
	$(MAKE) -C src/world
	$(MAKE) -C src/samplers
	$(MAKE) -C src/tracers
	$(MAKE) -C src/geometricobj
	$(MAKE) -C src/utilities
	@echo "obj es $(OBJ)"

-include $(DEP)
$(NAME): $(OBJ) $(LIBS)
	@echo "entro en name"
	gcc $(OBJ) $(LDFLAGS) $(LIB)  -o $(NAME)
	@echo "Creating binary $(NAME)"


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	@echo "objetos es  $(OBJ)"
	@mkdir -p $(@D)
	gcc $(DFLAGS) $(CFLAGS) -O3 -c $< -o $@
	@echo "Compiling.. $<"

clean:
ifneq ("$(wildcard $(OBJ) $(DEPENDS) $(OBJ_DIR))", "")
	rm -f $(OBJ) $(DEPENDS)
	rm -rf $(OBJ_DIR)
	@make clean -C src/parser/
	@make clean -C src/world/
	@make clean -C src/cameras
	@make clean -C src/geometricobj/
	@make clean -C src/maths/
	@make clean -C src/samplers/
	@make clean -C src/tracers/
	@make clean -C src/utilities/
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

	cd src/geometricobj && make fclean
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
