# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmickey <hmickey@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/18 16:28:35 by hmickey           #+#    #+#              #
#    Updated: 2021/02/18 17:06:10 by hmickey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libasm.a

INCLUDE		=	libasm.h

SRCS		=	ft_strcpy.s\
				ft_strlen.s

OBJS		= ${SRCS:.s=.o}

CC			= nasm

RM			= rm -f

FLAGS		=	-f macho64

.s.o:		
				${CC} ${FLAGS} $<


.PHONY:			all clean fclean re

$(NAME):		${OBJS} ${INCLUDE}
				ar rc ${NAME} ${OBJS}

all:			${NAME}

clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all