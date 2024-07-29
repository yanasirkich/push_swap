/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:53:26 by ysirkich          #+#    #+#             */
/*   Updated: 2024/05/21 19:20:29 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '\0')
		{
			count += ft_format(*(++str), args);
			if (count == -1)
				return (-1);
		}
		else if ((write(1, str, 1) == -1))
		{
			va_end(args);
			return (-1);
		}
		else
			count++;
		str++;
	}
	va_end(args);
	return (count);
}

int	ft_format(char format, va_list args)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		count += ft_putptr(va_arg(args, unsigned long));
	else if (format == 'd' || format == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		count += ft_putundec(va_arg(args, unsigned int));
	else if (format == 'x')
		count += ft_puthexdec(va_arg(args, unsigned int), 0);
	else if (format == 'X')
		count += ft_puthexdec(va_arg(args, unsigned int), 1);
	else if (format == '%')
		count += ft_putchar('%');
	else
		return (-1);
	if (count == -1)
		return (-1);
	return (count);
}

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}
