# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/27 14:08:57 by elias             #+#    #+#              #
#    Updated: 2023/02/06 13:06:37 by ezanotti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S_PPX_LIST	= ${D_SRC}main.c		\
	${D_SRC}ft_struct_init.c		\
	${D_GNL}get_next_line.c			\
	${D_GNL}get_next_line_utils.c	\
	${D_UTILS}ft_error.c			\
	${D_UTILS}ft_free.c				\
	${D_UTILS}ft_get_path.c			\
	${D_UTILS}ft_open.c				\
	${D_UTILS}ft_pipe.c				\
	${D_UTILS}ft_putstr.c			\

OBJS	= $(patsubst %.c, $(DIR_OBJS)%.o, $(S_PPX_LIST))

# VARIABLES
NAME	= pipex
CC		= cc

# DIRECTORIES
D_OBJS = .objs/
D_INC	= includes/
D_LIB	= libft/
D_GNL	= gnl/
D_SRC	= mandatory/
D_UTILS	= utils/

# FLAGS
MAKEFLAGS += --no-print-directory
CFLAGS	= -Wall -Wextra -Werror -g3
LIBFT 	= -L ./libft -lft 

# COMMANDS
RM		= rm -rf
PRINT = @printf

# COLORS
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
CYAN	= \033[1;36m
DEFAULT	= \033[0m
SUPPR	= \r\033[2K

all:	${NAME}

bonus:	all

${DIR_OBJS}%.o: %.c	${D_INC}pipex.h Makefile
		@mkdir -p $(shell dirname $@)
		@${PRINT} "${YELLOW}${SUPPR}Creating ${NAME}'s objects : $@"
		@${CC} ${CFLAGS} -I ${D_LIB} -I ${D_GNL} -I ${D_INC} -c $< -o $@ 

${NAME}:ascii lib ${OBJS}
		@${PRINT} "${GREEN}${SUPPR}Creating ${NAME}'s objects : DONE\n"
		@${PRINT} "${YELLOW}Compiling ${NAME}...${DEFAULT}"
		@${CC} -fsanitize=address ${OBJS} -o ${NAME} ${LIBFT}
		@${PRINT} "${GREEN}${SUPPR}Compiling ${NAME} : DONE ${DEFAULT}\n\n"

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
		@${RM} ${NAME} 

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

export ASCII

.PHONY : all re clean fclean lib ascii
