/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:23:30 by ysirkich@st       #+#    #+#             */
/*   Updated: 2024/07/29 19:09:13 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int	value;
	struct	s_stack	*next;
	struct s_stack	*prev;
}   t_stack;

int	instructions(t_stack **stack_a, t_stack **stack_b, char *command);
void	execute(t_stack **stack_a, t_stack **stack_b, char *command, int times);
t_stack *ft_first_node(t_stack *node);
t_stack *ft_last_node(t_stack *node);
int	ft_lstsize(t_stack *stack);
void	ft_lstadd_back(t_stack **stack, t_stack *new_node);
t_stack	*ft_lstnew(int value);
void ft_lst_free(t_stack **stack);
void	push_swap(t_stack **stack_a, t_stack **stack_b, int size);
int	sorted_lst(t_stack **stack_a);
void	push_smallest(t_stack **stack_a, t_stack **stack_b, int size);

int error(char *text);


#endif