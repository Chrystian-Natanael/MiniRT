#* ******************************************************************************#
#                                   NAME                                         #
#* ******************************************************************************#

NAME = puttingTogether8
FILE_EXTENSION = .c
.DEFAULT_GOAL := all
.PHONY: all clean fclean re tests help
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

SRCS_PATH = ./
SRCS2_PATH = ../../src/
INCS_PATH = ./ ../../includes/ ../../libs/garbage-collector/include/ ../../libs/MLX42/include/ ../../libs/libft/include/
BUILD_DIR := build/
TARGET_DIR = bin/
LIBFT_DIR := ../../libs/libft/
CODAM_DIR := ../../libs/MLX42/
GARB_DIR := ../../libs/garbage-collector/

#* ******************************************************************************#
#                                   FILES                                        #
#* ******************************************************************************#

SRCS =	$(SRCS2_PATH)00-mem_pool/Mem_pool.c \
		$(SRCS2_PATH)01-Tuples/Addition.c \
		$(SRCS2_PATH)01-Tuples/Cross_Product.c \
		$(SRCS2_PATH)01-Tuples/Dot_Product.c \
		$(SRCS2_PATH)01-Tuples/Magnitude.c \
		$(SRCS2_PATH)01-Tuples/Negating.c \
		$(SRCS2_PATH)01-Tuples/Normalization.c \
		$(SRCS2_PATH)01-Tuples/Scalar_Division.c \
		$(SRCS2_PATH)01-Tuples/Scalar_Multiplication.c \
		$(SRCS2_PATH)01-Tuples/Subtraction.c \
		$(SRCS2_PATH)01-Tuples/Tuples.c \
		$(SRCS2_PATH)06-Colors/Addition_Colors.c \
		$(SRCS2_PATH)06-Colors/Colors.c \
		$(SRCS2_PATH)06-Colors/Hada_Colors.c \
		$(SRCS2_PATH)06-Colors/Multiplication_Colors.c \
		$(SRCS2_PATH)06-Colors/Subtraction_Colors.c \
		$(SRCS2_PATH)00-Utils/Convert.c \
		$(SRCS2_PATH)00-Utils/Equal.c \
		$(SRCS2_PATH)00-Utils/Error.c \
		$(SRCS2_PATH)08-Canvas/Codam.c \
		$(SRCS2_PATH)08-Canvas/Render.c \
		$(SRCS2_PATH)02-Matrices/Cofactor.c \
		$(SRCS2_PATH)02-Matrices/Determinant.c \
		$(SRCS2_PATH)02-Matrices/Get_Set_Matrix.c \
		$(SRCS2_PATH)02-Matrices/Inverse.c \
		$(SRCS2_PATH)02-Matrices/Matrices.c \
		$(SRCS2_PATH)02-Matrices/Matrix_Multiplication.c \
		$(SRCS2_PATH)02-Matrices/Matrix_Transposition.c \
		$(SRCS2_PATH)02-Matrices/Minor.c \
		$(SRCS2_PATH)02-Matrices/Rotation.c \
		$(SRCS2_PATH)02-Matrices/Scaling.c \
		$(SRCS2_PATH)02-Matrices/Submatrix.c \
		$(SRCS2_PATH)02-Matrices/Translation.c \
		$(SRCS2_PATH)04-Objects/Objects.c \
		$(SRCS2_PATH)04-Objects/Sphere/Sphere.c \
		$(SRCS2_PATH)04-Objects/Planes/Planes.c \
		$(SRCS2_PATH)03-Intersections/Intersections.c \
		$(SRCS2_PATH)03-Intersections/lst_functions.c \
		$(SRCS2_PATH)03-Intersections/Intersections_objects.c \
		$(SRCS2_PATH)03-Intersections/Ray_and_hit.c \
		$(SRCS2_PATH)03-Intersections/Intersections_world.c \
		$(SRCS2_PATH)05-Light_and_Shading/Normal_at.c \
		$(SRCS2_PATH)05-Light_and_Shading/Reflection.c \
		$(SRCS2_PATH)07-Scenes/Camera.c \
		$(SRCS2_PATH)07-Scenes/Prepare_computations.c \
		$(SRCS2_PATH)07-Scenes/Shade.c \
		$(SRCS2_PATH)07-Scenes/View_transform.c \
		$(SRCS2_PATH)07-Scenes/World.c \
		$(SRCS2_PATH)07-Scenes/Is_shadowed.c \
		$(wildcard $(SRCS_PATH)*$(FILE_EXTENSION))
OBJS = $(SRCS:%$(FILE_EXTENSION)=$(BUILD_DIR)%.o)
DEPS = $(OBJS:.o=.d)

#* ******************************************************************************#
#                                    COMMANDS                                    #
#* ******************************************************************************#

MKDIR := mkdir -p
RM := rm -rf
SLEEP = sleep 0.1
COMP = gcc
SHELL := /bin/bash

#* ******************************************************************************#
#                                 FLAGS E COMP                                   #
#* ******************************************************************************#

CFLAGS = -Wall -Wextra -O2
DFLAGS = -Wall -Wextra -O2
LDLIBS = -ldl -lglfw -pthread -lm
LDFLAGS = $(LIBFT_DIR)libft.a $(GARB_DIR)garbage_collector.a $(CODAM_DIR)build/libmlx42.a
CPPFLAGS = $(addprefix -I,$(INCS_PATH)) -MMD -MP
COMP_OBJ = $(COMP) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
COMP_EXE = $(COMP) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(TARGET_DIR)$(NAME)

#* ******************************************************************************#
#                                  FUNCTIONS                                     #
#* ******************************************************************************#

define create_dir
	$(MKDIR) $(dir $@)
endef

define comp_objs
	$(eval COUNT=$(shell expr $(COUNT) + 1))
	$(COMP_OBJ)
	$(SLEEP)
	printf "Compiling $(NAME) $(YELLOW) %d%%\r$(FCOLOR)" $$(echo $$(($(COUNT) * 100 / $(words $(SRCS)))))
endef

define comp_exe
	$(MKDIR) $(TARGET_DIR)
	$(COMP_EXE)
	printf "\n"
	printf "$(GREEN)$(NAME) ->$(RESET)$(PURPLE) Is Ready in directory '$(TARGET_DIR)'\n$(RESET)"
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
endef

#* ******************************************************************************#
#                                   TARGETS                                      #
#* ******************************************************************************#

all: $(NAME)

$(BUILD_DIR)%.o: %$(FILE_EXTENSION)
	$(call create_dir)
	$(call comp_objs)

$(NAME): $(OBJS)
	$(call comp_exe)

clean:
	$(RM) $(BUILD_DIR)

fclean: clean
	$(RM) $(TARGET_DIR)
	$(RM) tests/build/

re: fclean all

run:
	./bin/$(NAME)

help:
	$(call help)
prof:
	gprof ./bin/$(NAME) gmon.out > prof
	< prof gprof2dot | dot -Tpng -o output.png

-include $(DEPS)
