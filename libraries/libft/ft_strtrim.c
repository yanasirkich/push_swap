/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:05:17 by ysirkich          #+#    #+#             */
/*   Updated: 2024/05/30 01:40:34 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set(char a, const char *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	size_t		before;
	size_t		after;
	int			i;

	before = 0;
	after = ft_strlen(s1);
	while (s1[before] && ft_set(s1[before], set))
		before++;
	while (after > before && ft_set(s1[after - 1], set))
		after--;
	str = (char *)malloc((after - before + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (before < after)
	{
		str[i] = s1[before];
		i++;
		before++;
	}
	str[i] = '\0';
	return (str);
}

static int	ft_set(char a, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == a)
			return (1);
		i++;
	}
	return (0);
}
