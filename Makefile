# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 14:08:57 by elias             #+#    #+#              #
#    Updated: 2023/02/02 14:27:34 by elias            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OS	= $(shell uname -s)

ifeq ($(OS), Linux)
	PRINT = @echo -ne
endif
ifeq ($(OS), Darwin)
	PRINT = @printf
endif

S_PPX_LIST	= main.c				\
	${D_UTILS}ft_putstr.c			\
	${D_UTILS}ft_error.c			\
	${D_UTILS}ft_open.c				\
	${D_GNL}get_next_line.c			\
	${D_GNL}get_next_line_utils.c	\
	ft_struct_init.c				\
	ft_pipe.c						\
	ft_get_path.c					\

OBJS = $(patsubst %.c, $(DIR_OBJS)%.o, $(S_PPX))
S_PPX	= ${addprefix ${DIR_SRC}, ${S_PPX_LIST}}

# DIRECTORIES
DIR_OBJS = .objs/
DIR_INCLUDE = includes/
DIR_SRC = srcs/
D_UTILS	= utils/
D_GNL	= gnl/

# LIB
LIBFT 	= -L ./libft -lft 

# VARIABLES
NAME	= pipex
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g3
RM		= rm -rf
MAKEFLAGS += --no-print-directory

# COLORS
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
CYAN	= \033[1;36m
DEFAULT	= \033[0m
SUPPR	= \r\033[2K

# COMPILATION
all :		${NAME}

${DIR_OBJS}%.o: %.c	${DIR_INCLUDE}pipex.h Makefile
			@mkdir -p $(shell dirname $@)
			@${PRINT} "${YELLOW}${SUPPR}Creating ${NAME}'s objects : $@"
			@${CC} ${CFLAGS} -I ./libft -I ./srcs/gnl -I ${DIR_INCLUDE} -c $< -o $@ 

${NAME}:	ascii lib ${OBJS}
			@${PRINT} "${GREEN}${SUPPR}Creating ${NAME}'s objects : DONE\n"
			@${PRINT} "${YELLOW}Compiling ${NAME}...${DEFAULT}"
			@${CC} -fsanitize=address ${OBJS} -o ${NAME} ${LIBFT}
			@${PRINT} "${GREEN}${SUPPR}Compiling ${NAME} : DONE ${DEFAULT}\n\n"

lib :
			@make -C ./libft

ascii :
			@${PRINT} "$$ASCII"

clean :		ascii
			@${PRINT} "${RED}Deleting objects : DONE\n"
			@${RM} ${DIR_OBJS}

fclean :	clean 
			@${PRINT} "${RED}Cleaning libft : DONE\n"
			@${MAKE} fclean -C ./libft
			@${PRINT} "${RED}Deleting executable : DONE${DEFAULT}\n\n"
			@${RM} ${NAME} 

re :		fclean all

define ASCII 
${CYAN}
 ██▓███   ██▓ ██▓███  ▓█████ ▒██   ██▒
▓██░  ██▒▓██▒▓██░  ██▒▓█   ▀ ▒▒ █ █ ▒░
▓██░ ██▓▒▒██▒▓██░ ██▓▒▒███   ░░  █   ░
▒██▄█▓▒ ▒░██░▒██▄█▓▒ ▒▒▓█  ▄  ░ █ █ ▒ 
▒██▒ ░  ░░██░▒██▒ ░  ░░▒████▒▒██▒ ▒██▒
▒▓▒░ ░  ░░▓  ▒▓▒░ ░  ░░░ ▒░ ░▒▒ ░ ░▓ ░
░▒ ░      ▒ ░░▒ ░      ░ ░  ░░░   ░▒ ░
░░        ▒ ░░░          ░    ░    ░  
          ░              ░  ░ ░    ░  
${DEFAULT}

endef

export ASCII

.PHONY : all re clean fclean lib ascii
