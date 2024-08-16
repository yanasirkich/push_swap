# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 15:07:54 by ysirkich          #+#    #+#              #
#    Updated: 2024/08/16 14:10:34 by ysirkich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libft.a

CC	=	cc

CFILES	=	ft_atoi	ft_strcmp	ft_putstr_fd	ft_split	ft_substr	\
			ft_strdup	ft_strlen	ft_isdigit	\

CFLAGS	=	-Wall	-Werror	-Wextra	-I./

AR	=	ar
RM	=	rm	-f

SRC_DIR	=	./

SRC	=	$(addprefix	$(SRC_DIR),	$(addsuffix	.c,	$(CFILES)))
OBJ	=	$(addprefix	$(SRC_DIR),	$(addsuffix	.o,	$(CFILES)))

$(NAME):	$(OBJ)
	@echo "Compiling library..."
	@$(AR) rcs	$@	$^

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

clean:
	@echo "Cleaning library..."
	@$(RM)	$(OBJ) $(BONUS_OBJS)

fclean: clean
	@echo "Removing library executable..."
	@$(RM)	$(NAME)

re:	fclean all

.PHONY:	all	clean	fclean	re	bonus
