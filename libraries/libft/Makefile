# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/10 15:07:54 by ysirkich          #+#    #+#              #
#    Updated: 2024/05/30 01:28:24 by ysirkich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libft.a

CC	=	cc

CFILES	=	ft_calloc	ft_isascii	ft_memchr	ft_memmove	ft_strdup	\
         ft_strlen	ft_tolower	ft_atoi	ft_isalnum	ft_isdigit	\
         ft_memcmp	ft_memset	ft_strlcat	ft_strnstr	ft_toupper	\
         ft_bzero	ft_isalpha	ft_isprint	ft_memcpy	ft_strchr	\
         ft_strlcpy	ft_strrchr	ft_strncmp	ft_strtrim	ft_putchar_fd	\
		 ft_putendl_fd	ft_putnbr_fd	ft_putstr_fd	ft_substr	\
		 ft_strjoin	ft_split	ft_itoa	ft_strmapi	ft_striteri

BONUSFILES	=	ft_lstnew_bonus	ft_lstadd_front_bonus	ft_lstsize_bonus	\
				ft_lstlast_bonus	ft_lstadd_back_bonus	ft_lstdelone_bonus	\
				ft_lstclear_bonus	ft_lstiter_bonus	ft_lstmap_bonus	\

CFLAGS	=	-Wall	-Werror	-Wextra	-I./

AR	=	ar
RM	=	rm	-f

SRC_DIR	=	./
BONUS_DIR = ./bonus/

SRC	=	$(addprefix	$(SRC_DIR),	$(addsuffix	.c,	$(CFILES)))
BONUS_SRC = $(addprefix $(BONUS_DIR), $(addsuffix .c, $(BONUSFILES)))

OBJ_DIR	=	./
OBJ	=	$(addprefix	$(OBJ_DIR),	$(addsuffix	.o,	$(CFILES)))
BONUS_OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(BONUSFILES)))

$(NAME):	$(OBJ)
	$(AR) rcs	$@	$^

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(BONUS_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus:	$(BONUS_OBJS)
	$(AR) rcs $(NAME)	$^
	@touch .bonus

all:	$(NAME)

clean:
	$(RM)	$(OBJ) $(BONUS_OBJS)	.bonus

fclean: clean
	$(RM)	$(NAME)

re:	fclean all

.PHONY:	all	clean	fclean	re	bonus
