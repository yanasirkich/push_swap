# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysirkich <ysirkich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 14:56:41 by ysirkich          #+#    #+#              #
#    Updated: 2024/05/22 12:54:23 by ysirkich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CC	=	cc
RM  = rm -f
AR	=	ar	rcs
CFLAGS	=	-Wall	-Werror	-Wextra

SRC	=	ft_printf.c	ft_printformat.c
OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

%.o:	%.c
	$(CC)	$(CFLAGS)	-c	$<	-o	$@

$(NAME):	$(OBJ)
		@$(AR) $(NAME)	$(OBJ)

clean:
		$(RM)	$(OBJ)

fclean:	clean
		$(RM)	$(NAME)

re:	fclean	all
.PHONY:	all clean fclean re