# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 14:08:57 by elias             #+#    #+#              #
#    Updated: 2023/02/06 13:46:39 by ezanotti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S_SRC	= ${D_SRC}main.c				\
		${D_SRC}ft_struct_init.c		\
		${D_GNL}get_next_line.c			\
		${D_GNL}get_next_line_utils.c	\
		${D_UTILS}ft_error.c			\
		${D_UTILS}ft_free.c				\
		${D_UTILS}ft_get_path.c			\
		${D_UTILS}ft_open.c				\
		${D_UTILS}ft_pipe.c				\
		${D_UTILS}ft_putstr.c			\

S_BNS	= ${D_BNS}main.c				\
		${D_BNS}ft_struct_init.c		\
		${D_GNL}get_next_line.c			\
		${D_GNL}get_next_line_utils.c	\
		${D_UTILS}ft_error.c			\
		${D_UTILS}ft_free.c				\
		${D_UTILS}ft_get_path.c			\
		${D_UTILS}ft_open.c				\
		${D_UTILS}ft_pipe.c				\
		${D_UTILS}ft_putstr.c			\

O_SRC	= $(patsubst %.c, ${D_OBJS}%.o, $(S_SRC))
O_BNS	= $(patsubst %.c, ${D_OBJS}%.o, $(S_BNS))

# VARIABLES
NAME	= pipex
CC		= cc

# FLAGS
MAKEFLAGS += --no-print-directory
CFLAGS	= -Wall -Wextra -Werror -g3
LIBFT 	= -L ./libft -lft 

# COMMANDS
RM		= rm -rf
PRINT	= @printf

# DIRECTORIES
D_OBJS	= .objs/
D_GNL	= gnl/
D_INC	= includes/
D_LIB	= libft/
D_UTILS	= utils/
D_SRC	= mandatory/
D_BNS	= bonus/

# COLORS
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
CYAN	= \033[1;36m
DEFAULT	= \033[0m
SUPPR	= \r\033[2K

all:	${NAME}

${D_OBJS}%.o: %.c	${D_INC}pipex.h Makefile
		@mkdir -p $(shell dirname $@)
		@${PRINT} "${YELLOW}${SUPPR}Creating ${NAME}'s objects : $@"
		@${CC} ${CFLAGS} -I ${D_LIB} -I ${D_GNL} -I ${D_INC} -c $< -o $@ 

${NAME}:ascii lib ${O_SRC}
		@${PRINT} "${GREEN}${SUPPR}Creating ${NAME}'s objects : DONE\n"
		@${PRINT} "${YELLOW}Compiling ${NAME}...${DEFAULT}"
		@${CC} -fsanitize=address ${O_SRC} -o ${NAME} ${LIBFT}
		@${PRINT} "${GREEN}${SUPPR}Compiling ${NAME} : DONE ${DEFAULT}\n\n"

bonus:	ascii lib ${O_BNS}
		@${PRINT} "${GREEN}${SUPPR}Creating ${NAME}_bonus's objects : DONE\n"
		@${PRINT} "${YELLOW}Compiling ${NAME}_bonus...${DEFAULT}"
		@${CC} -fsanitize=address ${O_SRC} -o ${NAME}_bonus ${LIBFT}
		@${PRINT} "${GREEN}${SUPPR}Compiling ${NAME}_bonus : DONE ${DEFAULT}\n\n"

lib:
		@make -C ./libft

ascii:
		@${PRINT} "$$ASCII\n"

clean:	ascii
		@${PRINT} "${RED}Deleting objects : DONE\n"
		@${RM} ${D_OBJS}

fclean:	clean 
		@${PRINT} "${RED}Cleaning libft : DONE\n"
		@${MAKE} fclean -C ./libft
		@${PRINT} "${RED}Deleting executable : DONE${DEFAULT}\n\n"
		@${RM} ${NAME} ${NAME}_bonus

re:		fclean all

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

export	ASCII

.PHONY:	all re clean fclean lib ascii bonus
