# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/02 14:41:58 by ysirkich          #+#    #+#              #
#    Updated: 2024/07/05 17:13:53 by ysirkich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
//BONUS = checker//
CC = gcc
RM = rm -f
INCLUDES = -Iincludes -Ilib/ft_printf/includes -Ilib/libft/includes
CFLAGS = -Wall -Wextra -Werror -ggdb -fsanitize=address