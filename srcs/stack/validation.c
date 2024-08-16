#include "push_swap.h"
#include "libft.h"

int	if_unique(t_stack *node, int number);
int	push_swap_atoi(char *str, t_stack *stack_a);

int	if_valid(char *str, t_stack *stack_a)
{
	int	number;
	
	//if (str[0] == '\0')
	//	return (-1);
	number = push_swap_atoi(str, stack_a);
	if (if_unique(stack_a, number) == -1)
		return (-1);
	return (0);
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
	long long	number;
	int			sign;
	int			index;

	number = 0;
	sign = 1;
	index = 0;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while (str[index])
	{
		if (!ft_isdigit(str[index]))
			return (-1);
		number = number * 10 + (str[index] - '0');
		if ((number * sign) > INT_MAX || (number * sign) < INT_MIN)
			return (-1);
		index++;
	}
	return ((int)(number * sign));
}
