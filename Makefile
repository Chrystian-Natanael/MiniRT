#* ******************************************************************************#
#                                   NAME                                         #
#* ******************************************************************************#

NAME = miniRT
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

SRCS_PATH = src/
INCS_PATH = includes/ libs/MLX42/include/ libs/garbage-collector/include/
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
SRCS = $(shell find $(SRCS_PATH) -type f -name "*$(FILE_EXTENSION)")
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

CFLAGS = -Wall -Wextra -Werror
DFLAGS = -Wall -Wextra -Werror -g3
LDLIBS = -ldl -lglfw -pthread
LDFLAGS = $(LIBFT_DIR)libft.a $(GARB_DIR)garbage_collector.a
CPPFLAGS = $(addprefix -I,$(INCS_PATH)) -MMD -MP
COMP_OBJ = $(COMP) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
COMP_EXE = $(COMP) $(CPPFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $(TARGET_DIR)$(NAME)

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
	cd tests && cmake -B build && $(MAKE) -C build && ./build/run_tests

run:
	./bin/$(NAME)
help:
	$(call help)

-include $(DEPS)
