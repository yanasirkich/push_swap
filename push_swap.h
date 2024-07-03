/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:23:30 by ysirkich@st       #+#    #+#             */
/*   Updated: 2024/07/02 20:31:57 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int	value;
	int	index;
	struct	the_stack	*next;
	struct the_stack	*prev;
}   t_stack;

t_stack *ft_lstnew(int value);
void ft_lstadd_back(t_stack **stack, t_stack *new_node);
int ft_lstsize(t_stack *stack);
void ft_lst_free(t_stack **stack);
void ft_argument_check(int argc, char **argv, t_stack **a);
void ft_print_lst(t_stack **a, int count, char **args);
void ft_lst_split(t_stack **a, t_stack **b, int size);
int ft_atoi(const char *str);
char **ft_split(char const *s, char c);

#endif