#* ******************************************************************************#
#                                   NAME                                         #
#* ******************************************************************************#

NAME = miniRT
NAME_BONUS = miniRT_bonus
FILE_EXTENSION = .c
.DEFAULT_GOAL := all
.PHONY: all clean fclean re tests help bonus
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
SRCS_BONUS_PATH = bonus/src/
INCS_PATH = includes/ libs/MLX42/include/ libs/garbage-collector/include/ libs/libft/include/
INCS_BONUS_PATH = bonus/includes/ libs/MLX42/include/ libs/garbage-collector/include/ libs/libft/include/
BUILD_DIR := build/
BUILD_DIR_BONUS := build/bonus/
TARGET_DIR = bin/
TARGET_DIR_BONUS = bin/bonus/
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
SRCS = $(addprefix $(SRCS_PATH), \
		00-mem_pool/Mem_Pool.c \
		00-mem_pool/Count_Pool.c \
		00-Utils/Convert.c \
		00-Utils/Equal.c \
		00-Utils/Error.c \
		00-Utils/Swap.c \
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
		03-Intersections/Intersections_Objects.c \
		03-Intersections/Intersections_World.c \
		03-Intersections/Intersect_Cone.c \
		03-Intersections/Intersections.c \
		03-Intersections/Lst_Functions.c \
		03-Intersections/Ray_and_Hit.c \
		04-Objects/Planes/Planes.c \
		04-Objects/Sphere/Sphere.c \
		04-Objects/Cylinders/Cylinders.c \
		04-Objects/Cone/Cone.c \
		04-Objects/Objects.c \
		05-Light_and_Shading/Normal_At.c \
		05-Light_and_Shading/Reflection.c \
		06-Colors/Addition_Colors.c \
		06-Colors/Colors.c \
		06-Colors/Hada_Colors.c \
		06-Colors/Multiplication_Colors.c \
		06-Colors/Subtraction_Colors.c \
		07-Scenes/Camera.c \
		07-Scenes/Is_shadowed.c \
		07-Scenes/Prepare_Computations.c \
		07-Scenes/Shade.c \
		07-Scenes/View_Transform.c \
		07-Scenes/World.c \
		08-Canvas/Codam.c \
		08-Canvas/Render.c \
		08-Canvas/Ppm.c \
		09-Patterns/Checker.c \
		09-Patterns/Gradient.c \
		09-Patterns/Patterns.c \
		09-Patterns/Ring.c \
		09-Patterns/Stripes.c \
		10-Parser/Parse_Ambient.c \
		10-Parser/Parse_Camera.c \
		10-Parser/Parse_Color.c \
		10-Parser/Parse_Light.c \
		10-Parser/Parse_Position.c \
		10-Parser/Parse_Plane.c \
		10-Parser/Parse_Plane_Utils.c \
		10-Parser/Parse_Sphere.c \
		10-Parser/Parse_Cylinder.c \
		10-Parser/Parse_Pattern.c \
		10-Parser/Parse_Pattern_Utils.c \
		10-Parser/Parser_Utils.c \
		10-Parser/Parser.c \
		10-Parser/Validations.c \
		main.c \
		)

#! BONUS FILES
SRCS_BONUS = $(addprefix $(SRCS_BONUS_PATH), \
		00-mem_pool/Count_Pool_Bonus.c \
		00-mem_pool/Mem_Pool_Bonus.c \
		00-Utils/Convert_Bonus.c \
		00-Utils/Equal_Bonus.c \
		00-Utils/Error_Bonus.c \
		00-Utils/Swap_Bonus.c \
		00-Utils/ft_atod_Bonus.c \
		01-Tuples/Addition_Bonus.c \
		01-Tuples/Cross_Product_Bonus.c \
		01-Tuples/Dot_Product_Bonus.c \
		01-Tuples/Magnitude_Bonus.c \
		01-Tuples/Negating_Bonus.c \
		01-Tuples/Normalization_Bonus.c \
		01-Tuples/Scalar_Division_Bonus.c \
		01-Tuples/Scalar_Multiplication_Bonus.c \
		01-Tuples/Subtraction_Bonus.c \
		01-Tuples/Tuples_Bonus.c \
		02-Matrices/Cofactor_Bonus.c \
		02-Matrices/Determinant_Bonus.c \
		02-Matrices/Get_Set_Matrix_Bonus.c \
		02-Matrices/Inverse_Bonus.c \
		02-Matrices/Matrices_Bonus.c \
		02-Matrices/Matrix_Multiplication_Bonus.c \
		02-Matrices/Matrix_Transposition_Bonus.c \
		02-Matrices/Minor_Bonus.c \
		02-Matrices/Rotation_Bonus.c \
		02-Matrices/Scaling_Bonus.c \
		02-Matrices/Submatrix_Bonus.c \
		02-Matrices/Translation_Bonus.c \
		03-Intersections/Intersections_Objects_Bonus.c \
		03-Intersections/Intersections_World_Bonus.c \
		03-Intersections/Intersect_Cone_Bonus.c \
		03-Intersections/Intersections_Bonus.c \
		03-Intersections/Lst_Functions_Bonus.c \
		03-Intersections/Ray_and_Hit_Bonus.c \
		04-Objects/Planes/Planes_Bonus.c \
		04-Objects/Sphere/Sphere_Bonus.c \
		04-Objects/Cylinders/Cylinders_Bonus.c \
		04-Objects/Cone/Cone_Bonus.c \
		04-Objects/Objects_Bonus.c \
		05-Light_and_Shading/Normal_At_Bonus.c \
		05-Light_and_Shading/Reflection_Bonus.c \
		06-Colors/Addition_Colors_Bonus.c \
		06-Colors/Colors_Bonus.c \
		06-Colors/Hada_Colors_Bonus.c \
		06-Colors/Multiplication_Colors_Bonus.c \
		06-Colors/Subtraction_Colors_Bonus.c \
		07-Scenes/Camera_Bonus.c \
		07-Scenes/Is_shadowed_Bonus.c \
		07-Scenes/Prepare_Computations_Bonus.c \
		07-Scenes/Shade_Bonus.c \
		07-Scenes/View_Transform_Bonus.c \
		07-Scenes/World_Bonus.c \
		08-Canvas/Codam_Bonus.c \
		08-Canvas/Render_Bonus.c \
		08-Canvas/Ppm_Bonus.c \
		09-Patterns/Checker_Bonus.c \
		09-Patterns/Gradient_Bonus.c \
		09-Patterns/Patterns_Bonus.c \
		09-Patterns/Ring_Bonus.c \
		09-Patterns/Stripes_Bonus.c \
		10-Parser/Parse_Ambient_Bonus.c \
		10-Parser/Parse_Camera_Bonus.c \
		10-Parser/Parse_Color_Bonus.c \
		10-Parser/Parse_Light_Bonus.c \
		10-Parser/Parse_Position_Bonus.c \
		10-Parser/Parse_Plane_Bonus.c \
		10-Parser/Parse_Plane_Utils_Bonus.c \
		10-Parser/Parse_Sphere_Bonus.c \
		10-Parser/Parse_Cylinder_Bonus.c \
		10-Parser/Parse_Pattern_Bonus.c \
		10-Parser/Parse_Pattern_Utils_Bonus.c \
		10-Parser/Parser_Utils_Bonus.c \
		10-Parser/Parser_Bonus.c \
		10-Parser/Validations_Bonus.c \
		main_Bonus.c \
		)
OBJS = $(SRCS:%$(FILE_EXTENSION)=$(BUILD_DIR)%.o)
OBJS_BONUS = $(SRCS_BONUS:%$(FILE_EXTENSION)=$(BUILD_DIR_BONUS)%.o)
DEPS = $(OBJS:.o=.d)
DEPS = $(OBJS_BONUS:.o=.d)
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

CFLAGS = -Wall -Wextra -Werror -Ofast
DFLAGS = -Wall -Wextra -Werror -g3 -pg
LDLIBS = -ldl -lglfw -pthread -lm
LDFLAGS = $(LIBFT_DIR)libft.a $(GARB_DIR)garbage_collector.a $(CODAM_DIR)build/libmlx42.a
CPPFLAGS = $(addprefix -I,$(INCS_PATH)) -MMD -MP
CPPFLAGSBONUS = $(addprefix -I,$(INCS_BONUS_PATH)) -MMD -MP

ifeq ($(D),1)
	COMP_OBJ = $(COMP) $(DFLAGS) $(CPPFLAGS) -c $< -o $@
	COMP_OBJ_BONUS = $(COMP) $(DFLAGS) $(CPPFLAGSBONUS) -c $< -o $@
else
	COMP_OBJ = $(COMP) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	COMP_OBJ_BONUS = $(COMP) $(CFLAGS) $(CPPFLAGSBONUS) -c $< -o $@
endif

ifeq ($(D),1)
	COMP_EXE = $(COMP) $(CPPFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -pg -o $(TARGET_DIR)$(NAME)
	COMP_BONUS_EXE = $(COMP) $(CPPFLAGSBONUS) $(OBJS_BONUS) $(LDFLAGS) $(LDLIBS) -pg -o $(TARGET_DIR)$(NAME_BONUS)
else
	COMP_EXE = $(COMP) $(CPPFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(TARGET_DIR)$(NAME)
	COMP_BONUS_EXE = $(COMP) $(CPPFLAGSBONUS) $(OBJS_BONUS) $(LDFLAGS) $(LDLIBS) -OFast -o $(TARGET_DIR)$(NAME_BONUS)
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

define comp_objs_bonus
	$(eval COUNT=$(shell expr $(COUNT) + 1))
	@if [ $(COUNT) -eq 1 ]; then \
		printf "$(YELLOW)Building miniRT files\n$(RESET)"; \
	fi
	$(COMP_OBJ_BONUS)
	$(SLEEP)
	printf "Compiling $(NAME_BONUS) $(YELLOW) %d%%\r$(FCOLOR)" $$(echo $$(($(COUNT) * 100 / $(words $(SRCS_BONUS)))))
	@if [ $(COUNT) -eq $(words $(SRCS_BONUS)) ]; then \
		printf " Compiled $(NAME_BONUS)$(DARK_GREEN) 100%%$(FCOLOR) ✅"; \
	fi
endef

define comp_exe
	$(MKDIR) $(TARGET_DIR)
	$(COMP_EXE)
	printf "\n\n"
	printf "$(GREEN)$(NAME) ->$(RESET)$(PURPLE) Is Ready in directory '$(TARGET_DIR)'\n$(RESET)"
endef

define comp_bonus_exe
	$(MKDIR) $(TARGET_DIR)
	$(COMP_BONUS_EXE)
	printf "\n\n"
	printf "$(GREEN)$(NAME_BONUS) ->$(RESET)$(PURPLE) Is Ready in directory '$(TARGET_DIR)'\n$(RESET)"
endef

define comp_libft
	printf "$(YELLOW)Building libft files\n$(RESET)"
	$(MAKE) -C $(LIBFT_DIR)
endef

define help
	echo "${DARK_RED}Available targets:${RESET}"
	printf "\n"
	echo "${DARK_BLUE}all:${RESET} ${LIGHT_GRAY}Build $(NAME)${RESET}"
	echo "${DARK_BLUE}bonus:${RESET} ${LIGHT_GRAY}Build $(NAME) bonus (if aplicable)${RESET}"
	echo "${DARK_BLUE}re:${RESET} ${LIGHT_GRAY}Rebuild the program${RESET}"
	echo "${DARK_BLUE}clean:${RESET} ${LIGHT_GRAY}Remove the object files${RESET}"
	echo "${DARK_BLUE}fclean:${RESET} ${LIGHT_GRAY}Remove the program and the object files${RESET}"
	echo "${DARK_BLUE}D=1:${RESET} ${LIGHT_GRAY}Build the program with debugging information${RESET}"
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

$(BUILD_DIR_BONUS)%.o: %$(FILE_EXTENSION)
	$(call create_dir)
	$(call comp_objs_bonus)

$(NAME): $(OBJS)
	$(call comp_exe)

$(LIBFT): $(CODAM_DIR)
	$(call comp_libft)
	$(call comp_codam)

$(NAME_BONUS): $(OBJS_BONUS)
	$(call comp_bonus_exe)

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

bonus: $(LIBFT) $(GARB) $(NAME_BONUS)

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
	./bin/$(NAME) $(MAP)

val:
	valgrind  --trace-children=yes --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --suppressions=.suppress_mlx_error.sup ./bin/$(NAME) $(MAP)

help:
	$(call help)

ifeq ($(PROF), 1)
	@gprof pit gmon.out > prof
	@< prof gprof2dot | dot -Tpng -o output.png
endif

-include $(DEPS)
