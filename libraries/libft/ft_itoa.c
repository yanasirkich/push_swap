/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:46:13 by ysirkich          #+#    #+#             */
/*   Updated: 2024/05/10 14:46:23 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	islength(int n);
static void	isastring(int n, char *str, int len, int sign);
static char	*handlemin(void);
static char	*handlezero(void);

char	*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		len;

	sign = 0;
	if (n == 0)
		return (handlezero());
	if (n == -2147483648)
		return (handlemin());
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	len = islength(n);
	str = malloc((len + sign + 1) * (sizeof(char)));
	if (!str)
		return (NULL);
	if (sign)
		str[0] = '-';
	isastring(n, str, len, sign);
	str[len + sign] = '\0';
	return (str);
}

static int	islength(int n)
{
	int	len;
	int	temp;

	len = 0;
	temp = n;
	while (temp != 0)
	{
		temp /= 10;
		len++;
	}
	return (len);
}

static void	isastring(int n, char *str, int len, int sign)
{
	int	i;

	i = len - 1;
	if (sign)
		i++;
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
}

static char	*handlemin(void)
{
	char	*str;

	str = malloc(12);
	if (!str)
		return (NULL);
	ft_strlcpy(str, "-2147483648", 12);
	return (str);
}

static char	*handlezero(void)
{
	char	*str;

	str = malloc(2 * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}
