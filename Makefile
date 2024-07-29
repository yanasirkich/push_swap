# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/02 14:41:58 by ysirkich          #+#    #+#              #
#    Updated: 2024/07/28 16:22:56 by ysirkich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
NAME = push_swap
CC = gcc
RM = rm -f
CFLAGS = -Wall	-Wextra	-Werror
INCLUDE	=-I. -Iincludes -Ilibraries/printf -Ilibraries/libft

# Libraries
LIBFT_DIR = libraries/libft
PRINTF_DIR = libraries/printf

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

LIBS = -L$(LIBFT_DIR)	-L$(PRINTF_DIR)	-lft	-lftprintf

# Source directories
SRCS_DIR	=	srcs
ALGORITHM_DIR = $(SRCS_DIR)/algorithm
STACK_DIR = $(SRCS_DIR)/stack

# Source files
SRCS =	main.c	\
		$(ALGORITHM_DIR)/push_swap.c	\
		$(ALGORITHM_DIR)/sort_utils.c	\
		$(STACK_DIR)/stack_operations.c	\
		$(STACK_DIR)/stack_utils.c	\
		$(STACK_DIR)/lst_utils.c	\

# Object files
OBJ = $(SRCS:.c=.o)

# Rues 
.c.o:
	@echo "Compiling..."
	@$(CC)	$(CFLAGS)	$(INCLUDE)	-c	$<	-o	$@

$(NAME):	$(OBJ)	$(LIBFT)	$(PRINTF)
			@echo "Linking stuff..."
			@$(CC)	$(CFLAGS)	$(OBJ)	$(LIBS)	-o	$(NAME)
				
$(LIBFT):
		@$(MAKE)	-C	$(LIBFT_DIR)

$(PRINTF):
		@$(MAKE)	-C	$(PRINTF_DIR)

all	:	$(NAME)

clean:
	@echo "Cleaning..."
	@$(RM)	$(OBJ)
	@$(MAKE)	-C	$(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean

fclean:
	@echo "Removing executable..."
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re 