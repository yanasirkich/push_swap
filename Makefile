# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/02 14:41:58 by ysirkich          #+#    #+#              #
#    Updated: 2024/08/18 20:25:29 by ysirkich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
NAME = push_swap
CC = gcc
RM = rm -f
CFLAGS = -Wall	-Wextra	-Werror
INCLUDE	=-I. -Iincludes -Ilibft

# Libraries
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBS = -L$(LIBFT_DIR)	-lft

# Source directories
SRCS_DIR	=	srcs
ALGORITHM_DIR = $(SRCS_DIR)/algorithm
STACK_DIR = $(SRCS_DIR)/stack

# Source files
SRCS =	$(SRCS_DIR)/main.c	\
		$(ALGORITHM_DIR)/push_swap.c	\
		$(ALGORITHM_DIR)/sort_utils.c	\
		$(STACK_DIR)/stack_operations.c	\
		$(STACK_DIR)/stack_utils.c	\
		$(STACK_DIR)/lst_utils.c	\
		$(STACK_DIR)/validation.c

# Object files
OBJ = $(SRCS:.c=.o)

# Rues 
.c.o:
	@echo "Compiling $<..."
	@$(CC)	$(CFLAGS)	$(INCLUDE)	-c	$<	-o	$@

$(NAME):	$(OBJ)	$(LIBFT)
			@echo "Linking stuff..."
			@$(CC)	$(CFLAGS)	$(OBJ)	$(LIBS)	-o	$(NAME)
			@echo "$(NAME) created successfully!"
				
$(LIBFT):
		@echo "Building libft..."
		@$(MAKE)	-C	$(LIBFT_DIR)

all	:	$(NAME)

clean:
	@echo "Cleaning object files..."
	@$(RM)	$(OBJ)
	@$(MAKE)	-C	$(LIBFT_DIR) clean

fclean:
	@echo "Removing executable..."
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re 