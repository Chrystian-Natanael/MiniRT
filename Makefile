#* ******************************************************************************#
#                                   NAME                                         #
#* ******************************************************************************#

NAME = miniRT
FILE_EXTENSION = .c
.DEFAULT_GOAL := all
.PHONY: all clean fclean re tests help
TEST ?= *
MAP ?= /scenes/basic/1_sphere_pink.rt
.SILENT:

#* ******************************************************************************#
#                                   COLORS                                       #
#* ******************************************************************************#

DEFAULT=\033[39m
BLACK=\033[30m
DARK_RED=\033[31m
DARK_GREEN=\033[32m
DARK_YELLOW=\033[33m
DARK_BLUE=\033[34m
DARK_MAGENTA=\033[35m
DARK_CYAN=\033[36m
LIGHT_GRAY=\033[37m
DARK_GRAY=\033[90m
RED=\033[91m
GREEN=\033[92m
ORANGE=\033[93m
BLUE=\033[94m
MAGENTA=\033[95m
CYAN=\033[96m
WHITE=\033[97m
RESET = \033[0m

#* ******************************************************************************#
#                                   PATH                                         #
#* ******************************************************************************#

SRCS_PATH = src/
INCS_PATH = includes/ libs/MLX42/include/ libs/garbage-collector/include/ libs/libft/include/
BUILD_DIR := build/
TARGET_DIR = bin/
LIBFT_DIR := libs/libft/
GTEST_DIR = tests/googletest
CODAM_DIR := libs/MLX42/
GARB_DIR := libs/garbage-collector/

#* ******************************************************************************#
#                                   FILES                                        #
#* ******************************************************************************#

GTEST_REPO = git@github.com:google/googletest.git
CODAM_REPO = git@github.com:codam-coding-college/MLX42.git
GARB_REPO = git@github.com:Chrystian-Natanael/garbage-collector.git
LIBS := $(LIBFT_DIR)libft.a $(CODAM_DIR)build/libmlx42.a $(GARB_DIR)garbage_collector.a
GARB = $(addprefix $(GARB_DIR), garbage_collector.a)
# SRCS = $(shell find $(SRCS_PATH) -type f -name "*$(FILE_EXTENSION)") # PARA PEGAR TODOS OS ARQUIVOS
SRCS = $(addprefix $(SRCS_PATH), \
		00-mem_pool/Mem_pool.c \
		00-mem_pool/Count_pool.c \
		00-Utils/Convert.c \
		00-Utils/Equal.c \
		00-Utils/Error.c \
		00-Utils/ft_atod.c \
		01-Tuples/Addition.c \
		01-Tuples/Cross_Product.c \
		01-Tuples/Dot_Product.c \
		01-Tuples/Magnitude.c \
		01-Tuples/Negating.c \
		01-Tuples/Normalization.c \
		01-Tuples/Scalar_Division.c \
		01-Tuples/Scalar_Multiplication.c \
		01-Tuples/Subtraction.c \
		01-Tuples/Tuples.c \
		02-Matrices/Cofactor.c \
		02-Matrices/Determinant.c \
		02-Matrices/Get_Set_Matrix.c \
		02-Matrices/Inverse.c \
		02-Matrices/Matrices.c \
		02-Matrices/Matrix_Multiplication.c \
		02-Matrices/Matrix_Transposition.c \
		02-Matrices/Minor.c \
		02-Matrices/Rotation.c \
		02-Matrices/Scaling.c \
		02-Matrices/Submatrix.c \
		02-Matrices/Translation.c \
		03-Intersections/Intersections_objects.c \
		03-Intersections/Intersections_world.c \
		03-Intersections/Intersections.c \
		03-Intersections/lst_functions.c \
		03-Intersections/Ray_and_hit.c \
		04-Objects/Planes/Planes.c \
		04-Objects/Sphere/Sphere.c \
		04-Objects/Objects.c \
		05-Light_and_Shading/Normal_at.c \
		05-Light_and_Shading/Reflection.c \
		06-Colors/Addition_Colors.c \
		06-Colors/Colors.c \
		06-Colors/Hada_Colors.c \
		06-Colors/Multiplication_Colors.c \
		06-Colors/Subtraction_Colors.c \
		07-Scenes/Camera.c \
		07-Scenes/Is_shadowed.c \
		07-Scenes/Prepare_computations.c \
		07-Scenes/Shade.c \
		07-Scenes/View_transform.c \
		07-Scenes/World.c \
		08-Canvas/Codam.c \
		08-Canvas/Render.c \
		09-Patterns/Checker.c \
		09-Patterns/Gradient.c \
		09-Patterns/Patterns.c \
		09-Patterns/Ring.c \
		09-Patterns/Stripes.c \
		11-Parser/Parse_ambient.c \
		11-Parser/Parse_camera.c \
		11-Parser/Parse_color.c \
		11-Parser/Parse_light.c \
		11-Parser/Parse_position.c \
		11-Parser/Parse_plane.c \
		11-Parser/Parse_sphere.c \
		11-Parser/Parser_utils.c \
		11-Parser/Parser.c \
		11-Parser/Validations.c \
		main.c \
		)
OBJS = $(SRCS:%$(FILE_EXTENSION)=$(BUILD_DIR)%.o)
DEPS = $(OBJS:.o=.d)
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

#* ******************************************************************************#
#                                    COMMANDS                                    #
#* ******************************************************************************#

MKDIR := mkdir -p
RM := rm -rf
SLEEP = sleep 0.1
COMP = cc
SHELL := /bin/bash

#* ******************************************************************************#
#                                 FLAGS E COMP                                   #
#* ******************************************************************************#

CFLAGS = -Wall -Wextra -Werror -g3
DFLAGS = -Wall -Wextra -Werror -g3 -O2 -pg
LDLIBS = -ldl -lglfw -pthread -lm
LDFLAGS = $(LIBFT_DIR)libft.a $(GARB_DIR)garbage_collector.a $(CODAM_DIR)build/libmlx42.a
CPPFLAGS = $(addprefix -I,$(INCS_PATH)) -MMD -MP

ifeq ($(D),1)
	COMP_OBJ = $(COMP) $(DFLAGS) $(CPPFLAGS) -c $< -o $@
else
	COMP_OBJ = $(COMP) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
endif

ifeq ($(D),1)
	COMP_EXE = $(COMP) $(CPPFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -O2 -pg -o $(TARGET_DIR)$(NAME)
else
	COMP_EXE = $(COMP) $(CPPFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(TARGET_DIR)$(NAME)
endif

#* ******************************************************************************#
#                                  FUNCTIONS                                     #
#* ******************************************************************************#


define comp_codam
	cd libs/MLX42/ && cmake -B build && cd build && make
endef

define create_dir
	$(MKDIR) $(dir $@)
endef

define comp_garb
	printf "$(YELLOW)Building garb files\n$(RESET)"
	$(MAKE) -C $(GARB_DIR)
endef

define comp_objs
	$(eval COUNT=$(shell expr $(COUNT) + 1))
	@if [ $(COUNT) -eq 1 ]; then \
		printf "$(YELLOW)Building miniRT files\n$(RESET)"; \
	fi
	$(COMP_OBJ)
	$(SLEEP)
	printf "Compiling $(NAME) $(YELLOW) %d%%\r$(FCOLOR)" $$(echo $$(($(COUNT) * 100 / $(words $(SRCS)))))
	@if [ $(COUNT) -eq $(words $(SRCS)) ]; then \
		printf " Compiled $(NAME)$(DARK_GREEN) 100%%$(FCOLOR) ✅"; \
	fi
endef

define comp_exe
	$(MKDIR) $(TARGET_DIR)
	$(COMP_EXE)
	printf "\n\n"
	printf "$(GREEN)$(NAME) ->$(RESET)$(PURPLE) Is Ready in directory '$(TARGET_DIR)'\n$(RESET)"
endef

define comp_libft
	printf "$(YELLOW)Building libft files\n$(RESET)"
	$(MAKE) -C $(LIBFT_DIR)
endef

define help
	echo "${DARK_RED}Available targets:${RESET}"
	printf "\n"
	echo "${DARK_BLUE}all:${RESET} ${LIGHT_GRAY}Build $(NAME)${RESET}"
	echo "${DARK_BLUE}both:${RESET} ${LIGHT_GRAY}Build $(NAME) and $(NAME) bonus (if aplicable)${RESET}"
	echo "${DARK_BLUE}bonus:${RESET} ${LIGHT_GRAY}Build $(NAME) bonus (if aplicable)${RESET}"
	echo "${DARK_BLUE}re:${RESET} ${LIGHT_GRAY}Rebuild the program${RESET}"
	echo "${DARK_BLUE}clean:${RESET} ${LIGHT_GRAY}Remove the object files${RESET}"
	echo "${DARK_BLUE}fclean:${RESET} ${LIGHT_GRAY}Remove the program and the object files${RESET}"
	echo "${DARK_BLUE}debug:${RESET} ${LIGHT_GRAY}Build the program with debugging information${RESET}"
	echo "${DARK_BLUE}run:${RESET} ${LIGHT_GRAY}run the program without arguments${RESET}"
	echo "${DARK_BLUE}tests:${RESET} ${LIGHT_GRAY}build and run tests from test/ (Need format gtests)${RESET}"
endef

#* ******************************************************************************#
#                                   TARGETS                                      #
#* ******************************************************************************#

all: $(LIBFT) $(GARB) $(NAME)

$(BUILD_DIR)%.o: %$(FILE_EXTENSION)
	$(call create_dir)
	$(call comp_objs)

$(NAME): $(OBJS)
	$(call comp_exe)

$(LIBFT): $(CODAM_DIR)
	$(call comp_libft)
	$(call comp_codam)

clean:
	$(RM) $(BUILD_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(GARB_DIR) clean

fclean: clean
	$(RM) $(TARGET_DIR)
	$(RM) tests/build/
	$(RM) libs/MLX42/build
	$(RM) $(GTEST_DIR)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(GARB_DIR) fclean
	$(RM) prof
	$(RM) gmon.out

re: fclean all

$(GTEST_DIR):
	git clone $(GTEST_REPO) $(GTEST_DIR)

$(CODAM_DIR):
	git clone $(CODAM_REPO) $(CODAM_DIR)

$(GARB_DIR):
	git clone $(GARB_REPO) $(GARB_DIR)

$(GARB): $(GARB_DIR)
	$(call comp_garb)

tests: $(GTEST_DIR) $(LIBFT) $(GARB)
	cd tests && cmake -B build && $(MAKE) -C build && ./build/run_tests --gtest_filter=$(TEST)

run:
	./bin/$(NAME)
	# ./bin/$(NAME) $(MAP)

val: re
	valgrind  --trace-children=yes --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --suppressions=.suppress_mlx_error.sup ./bin/$(NAME)
	# valgrind  --trace-children=yes --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --suppressions=.suppress_mlx_error.sup ./bin/$(NAME) $(MAP)

help:
	$(call help)

ifeq ($(PROF), 1)
	@gprof pit gmon.out > prof
	@< prof gprof2dot | dot -Tpng -o output.png
endif

-include $(DEPS)
