# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/02 14:41:58 by ysirkich          #+#    #+#              #
#    Updated: 2024/07/24 23:23:15 by ysirkich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler

NAME = push_swap
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

# Libraries

LIBFT_DIR = ./libft
PRINTF_DIR = ./printf

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

# Source
ALGORITHM_DIR =	algorithm
STACK_DIR = stack
SRC_DIR	=	src

# Rues 

all	:	$(NAME)

$(NAME): $(LIBFT)	$(PRINTF)	$(OBJS)
	$(CC)	$(CFLAGS)	-o	$(NAME)	$(OBJS)	$(LIBFT)	$(PRINTF)

$(LIBFT):
	$(MAKE)	-C	$(LIBFT_DIR)
$(PRINTF):
	 $(MAKE)	-C	$(LIBFT_DIR)

clean:
	$(RM)	$(OBJS)
	$(MAKE)	-C	$(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean:
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re $(LIBFT) $(PRINTF)