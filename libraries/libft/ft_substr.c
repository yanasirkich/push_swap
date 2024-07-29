/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:05:44 by ysirkich          #+#    #+#             */
/*   Updated: 2024/05/30 01:41:01 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start,
size_t len)
{
	char	*str;
	size_t	i1;
	size_t	i2;

	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - (size_t)start;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i1 = 0;
	i2 = 0;
	while (s[i1])
	{
		if (i1 >= start && i2 < len)
		{
			str[i2] = s[i1];
			i2++;
		}
		i1++;
	}
	str[i2] = '\0';
	return (str);
}
