# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amartino <amartino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/26 11:56:39 by amartino          #+#    #+#              #
#    Updated: 2020/07/19 10:32:41 by amartinod        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
                     ####################################
                     #                   				#
                     #       	MAIN VARIABLES 			#
                     #                   				#
                     ####################################
NAME = corewar
ASM_DIR = asm_dir
VM_DIR = virtual_machine
LIB_DIR = libft
LIB = libft.a
CC = clang 
CFLAGS += -Wall -Wextra -Werror
LDFLAGS += `sdl2-config --libs --cflags` -lSDL2_image -lSDL2_ttf
INCLUDES += -I./include
INCLUDES += -I./libft/includes
INCLUDES += -I./libft/ft_printf/includes

HEAD += ./include/define_vm.h
HEAD += ./include/visu.h
HEAD += ./include/vm.h


                     ####################################
                     #                   				#
                     #       	  	IFEQ	   			#
                     #                   				#
                     ####################################
# FLAGS
ifeq ($(debug), 0)
	CFLAGS += -g3
else ifeq ($(debug), 1)
	CFLAGS += -g3
	CFLAGS += -fsanitize=address,undefined
else ifeq ($(debug), 2)
	CFLAGS += -g3
	CFLAGS += -fsanitize=address,undefined
	CFLAGS += -pedantic
else ifeq ($(debug), 3)
	CFLAGS += -g3
	CFLAGS += -fsanitize=address,undefined
	CFLAGS += -pedantic
	CFLAGS += -Wpadded
else ifeq ($(debug), 4)
	CFLAGS += -g3
	CFLAGS += -fsanitize=address,undefined
	CFLAGS += -pedantic
	CFLAGS += -Wpadded
	CFLAGS += -Weverything
endif

                     ####################################
                     #                   				#
                     #       		PATHS     			#
                     #                   				#
                     ####################################
# LIB
LIB_PATH = $(LIB_DIR)/$(LIB)

# SRCS
PATH_SRC += $(VM_DIR)/srcs
PATH_SRC += $(VM_DIR)/srcs/init
PATH_SRC += $(VM_DIR)/srcs/operation
PATH_SRC += $(VM_DIR)/srcs/battle
PATH_SRC += $(VM_DIR)/srcs/print
PATH_SRC += $(VM_DIR)/srcs/clean
PATH_SRC += $(VM_DIR)/visualizator
PATH_SRC += $(VM_DIR)/visualizator/init
PATH_SRC += $(VM_DIR)/visualizator/font
PATH_SRC += $(VM_DIR)/visualizator/clean

vpath %.c $(PATH_SRC)

                     ####################################
                     #                   				#
                     #       	   SOURCE      			#
                     #                   				#
                     ####################################
# main
SRCS += main

# init
SRCS += init_and_parse
SRCS += parse_player_file
SRCS += parsing_utilities
SRCS += set_up_arena

# operation
SRCS += check_bytecode_and_param
SRCS += op
SRCS += live
SRCS += ld
SRCS += st
SRCS += add_sub
SRCS += and_xor_or
SRCS += zjmp
SRCS += ldi
SRCS += sti
SRCS += fork
SRCS += lld
SRCS += lldi
SRCS += lfork
SRCS += aff

# battle
SRCS += battle
SRCS += lets_fight
SRCS += move_to_next_op
SRCS += get_param
SRCS += battle_utilities

# print
SRCS += option_dump
SRCS += print_output

# visu
SRCS += init_main_zone
SRCS += destroy_visual 
SRCS += active_zones
SRCS += font_writing
SRCS += setup_window 
SRCS += run_visu 
SRCS += winner 
SRCS += player_input
SRCS += player_box
SRCS += visu_tools
SRCS +=	arena
SRCS += info_box
SRCS += command_box

# clean
SRCS += clean
                     ####################################
                     #                   				#
                     #       	  VARIABLES    			#
                     #                   				#
                     ####################################
nb ?= 50
T ?= sample
VAL ?= no
REQUEST = 'read -p "Enter a commit message:" pwd; echo $$pwd'
COMMIT_MESSAGE ?= $(shell bash -c $(REQUEST))

                     ####################################
                     #                   				#
                     #              OBJS	   			#
                     #                   				#
                     ####################################
BUILD_DIR = objs/

OBJS = $(patsubst %, $(BUILD_DIR)%.o, $(SRCS))

                     ####################################
                     #                   				#
                     #       	   RULES      			#
                     #                   				#
                     ####################################
all: $(NAME)
	echo "\n$(CYAN)MAKE COMPLETE$(END)"

fast:
	$(MAKE) re -j8

$(NAME): $(OBJS) $(LIB_PATH) $(ASM_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJS) $(LIB_PATH) $(INCLUDES)

$(OBJS): $(BUILD_DIR)%.o: %.c $(HEAD) Makefile
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	echo "$(CFLAGS) \t\t $(GREEN)$<$(END)"

$(LIB_PATH): FORCE
	make -C $(LIB_DIR)

$(ASM_DIR): FORCE
	make -C $(ASM_DIR)

#unit_test:
#	@echo "\n | Unitest |"
#	./unit_test.sh

#run:
#	$(MAKE) unit_test

clean:
	rm -f $(OBJS)
	rm -rf ./$(BUILD_DIR)
	echo "$(YELLOW)OBJS$(END) \t\t were \t\t $(GREEN)clean$(END)\n"
	$(MAKE) clean -C $(LIB_DIR)
	$(MAKE) clean -C $(ASM_DIR)

fclean: clean
	rm -rf $(NAME)
	echo "$(YELLOW)$(NAME)$(END) \t\t was \t\t $(GREEN)clean$(END)\n"
	$(MAKE) fclean -C $(LIB_DIR)
	$(MAKE) fclean -C $(ASM_DIR)

re: fclean
	$(MAKE)

FORCE:

.PHONY: clean fclean all re t FORCE git
.SILENT: $(NAME) $(OBJS) $(BUILD_DIR) $(MAIN_OBJ_PS) $(MAIN_OBJ_C) all re t \
			$(LIB_PATH) $(NAME_PUSH_SWP) $(NAME_CHECKER) clean fclean run

                     ####################################
                     #                   				#
                     #        		GIT       			#
                     #                   				#
                     ####################################
git:
	@git add -A
	@git commit -m "$(COMMIT_MESSAGE)"
	@git push

                     ####################################
                     #                   				#
                     #       		COLOR     			#
                     #                  				#
                     ####################################
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
END = \033[0m
