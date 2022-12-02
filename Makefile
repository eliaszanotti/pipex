# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ezanotti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 15:45:18 by ezanotti          #+#    #+#              #
#    Updated: 2022/12/02 15:46:22 by ezanotti         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# SOURCES
S_LIB	= ${DIR}ft_isalpha.c ${DIR}ft_isdigit.c ${DIR}ft_isalnum.c \
		${DIR}ft_isascii.c ${DIR}ft_isprint.c ${DIR}ft_strlen.c \
		${DIR}ft_memset.c ${DIR}ft_bzero.c ${DIR}ft_memcpy.c \
		${DIR}ft_memmove.c ${DIR}ft_strlcpy.c ${DIR}ft_strlcat.c \
		${DIR}ft_toupper.c ${DIR}ft_tolower.c ${DIR}ft_strchr.c \
		${DIR}ft_strrchr.c ${DIR}ft_strncmp.c ${DIR}ft_memchr.c \
		${DIR}ft_memcmp.c ${DIR}ft_strnstr.c ${DIR}ft_atoi.c \
		${DIR}ft_calloc.c ${DIR}ft_strdup.c ${DIR}ft_substr.c \
		${DIR}ft_strjoin.c ${DIR}ft_strtrim.c ${DIR}ft_split.c \
		${DIR}ft_itoa.c ${DIR}ft_strmapi.c ${DIR}ft_striteri.c \
		${DIR}ft_putchar_fd.c ${DIR}ft_putstr_fd.c ${DIR}ft_putendl_fd.c \
		${DIR}ft_putnbr_fd.c ${DIR}ft_lstnew.c ${DIR}ft_lstadd_front.c \
		${DIR}ft_lstsize.c ${DIR}ft_lstlast.c ${DIR}ft_lstadd_back.c \
		${DIR}ft_lstdelone.c ${DIR}ft_lstclear.c ${DIR}ft_lstiter.c \
		${DIR}ft_lstmap.c

OBJS	= ${S_LIB:.c=.o}

# VARIABLES
NAME	= fdf
DIR		= libft/
DIR_SRC = srcs/
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

# COMPILATION
all :		${NAME}

%.o: %.c	${DIR}libft.h ${DIR_SRC}fdf.h Makefile
			${CC} ${CFLAGS} -I ${DIR} -I mlx -I ${DIR_SRC} -c $< -o ${<:.c=.o} 

${NAME}:	${OBJS}
			${CC} ${OBJS} -o ${NAME} ${MLX}

clean :
			${RM} ${OBJS}

fclean :	clean
			${RM} ${NAME} 

re :		fclean all

.PHONY : all re clean fclean
