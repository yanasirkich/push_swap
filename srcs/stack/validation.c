#include "push_swap.h"

int	if_valid(char *str, t_stack *stack_a)
{
	t_stack	*node;
	int	number;
	int	index;
	
	node = stack_a;
	index = 0;
	if(!ft_isdigit(str[index])) //dont forget to add this function lo libft
		return (-1);
	number = push_swap_atoi();
	if_unique(node, number);//when we have number through atoi


}

int	if_unique(t_stack *node, int number)
{
	while (node)
	{
		if (node->value == number)
			return (-1);
		node = node->next;
	}
	return (0);
}

int	push_swap_atoi(char *str, t_stack *stack_a)
{
	
}