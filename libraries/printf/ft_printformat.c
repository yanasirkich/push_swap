/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printformat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:02:02 by ysirkich          #+#    #+#             */
/*   Updated: 2024/05/30 14:47:37 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	count;
	int	written;

	if (!str)
		str = "(null)";
	count = 0;
	written = 0;
	while (str[count])
	{
		written = ft_putchar(str[count]);
		if (written == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	ft_putptr(unsigned long ptr)
{
	int	count;
	int	hex_value;

	count = 0;
	if (ft_putchar('0') == -1 || ft_putchar('x') == -1)
		return (-1);
	count += 2;
	hex_value = ft_puthexdec(ptr, 0);
	if (hex_value == -1)
		return (-1);
	count += hex_value;
	return (count);
}

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		if (write(1, "-2147483648", 11) != 11)
			return (-1);
		return (11);
	}
	if (nb < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		count++;
		nb = -nb;
	}
	if (nb >= 10)
	{
		count += ft_putnbr(nb / 10);
		if (count == -1)
			return (-1);
	}
	if (ft_putchar(nb % 10 + '0') == -1)
		return (-1);
	return (count + 1);
}

int	ft_putundec(unsigned int nb)
{
	char	buffer[11];
	int		count;
	int		i;

	if (nb == 0)
		return (ft_putchar('0'));
	i = 0;
	while (nb)
	{
		buffer[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	count = 0;
	while (i > 0)
	{
		if (ft_putchar(buffer[--i]) == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	ft_puthexdec(unsigned long nb, int upper)
{
	char	*hex;
	int		count;
	char	buffer[16];
	int		i;

	if (nb == 0)
		return (ft_putchar('0'));
	if (upper)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	i = 0;
	while (nb)
	{
		buffer[i++] = hex[nb % 16];
		nb /= 16;
	}
	count = 0;
	while (i-- > 0)
	{
		count += ft_putchar(buffer[i]);
		if (count == -1)
			return (-1);
	}
	return (count);
}
