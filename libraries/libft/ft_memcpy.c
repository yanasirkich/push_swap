/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich <ysirkich@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:51:09 by ysirkich          #+#    #+#             */
/*   Updated: 2024/05/10 14:51:13 by ysirkich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	dest = (unsigned char *) dst;
	s = (const unsigned char *) src;
	while (n > 0)
	{
		*dest = *s;
		dest++;
		s++;
		n--;
	}
	return (dst);
}
