# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eblondee <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/27 16:29:51 by eblondee          #+#    #+#              #
#    Updated: 2022/05/31 16:32:22 by eblondee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c \
		ft_check.c \
		ft_init_struct.c \
		ft_utils.c \
		ft_exec.c \

OBJS = ${SRCS:.c=.o}

NAME = pipex

CC  = gcc

RM  = rm -rf

DIR = ./libft/

LIB = libft.a

CFLAGS  = -Wall -Wextra -Werror -g

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
	make -C ${DIR} ${LIB}
	${CC} ${CFLAGS} ${OBJS} ${DIR}${LIB} -o ${NAME}

all:	${NAME}

clean:
	make -C ${DIR} clean
	${RM} ${OBJS}

fclean: clean
	${RM} ${DIR}${LIB}
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
