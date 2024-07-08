# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/02 14:41:58 by ysirkich          #+#    #+#              #
#    Updated: 2024/07/08 13:34:17 by ysirkich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler

NAME = push_swap
#BONUS = 
CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

# Libraries

LIBFT_DIR = ./libft
PRINTF_DIR = ./printf

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

# Rues 

all	:	$(NAME)

$(NAME): $(LIBFT)	$(PRINTF)	$(OBJS)
	$(CC)	$(CFLAGS)	-o	$(NAME)	$(OBJS)	$(LIBFT)	$(PRINTF)

$(LIBFT):
	$(MAKE)	-C	$(LIBFT_DIR)
$(PRINTF):
	 $(MAKE)	-C	$(LIBFT_DIR)
