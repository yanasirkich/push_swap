/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysirkich@student.hive.fi <ysirkich@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:17:04 by ysirkich@st       #+#    #+#             */
/*   Updated: 2024/06/22 15:20:04 by ysirkich@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int	ft_wordcount(const char *s, char c);
static char	*ft_extract_substring(const char **s, char c);
static void	ft_free(char **array);

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		nw;

	nw = ft_wordcount(s, c);
	array = (char **)malloc(sizeof(char *) * (nw + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			array[i++] = ft_extract_substring(&s, c);
			if (!array[i - 1])
			{
				ft_free(array);
				return (NULL);
			}
		}
	}
	array[i] = NULL;
	return (array);
}

static char	*ft_extract_substring(const char **s, char c)
{
	const char	*start;
	char		*substr;
	size_t		lw;

	lw = 0;
	start = *s;
	while (**s != c && **s)
	{
		lw++;
		(*s)++;
	}
	substr = ft_substr(start, 0, lw);
	if (!substr)
		substr = NULL;
	return (substr);
}

static int	ft_wordcount(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!s || !*s)
		return (0);
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c))
			count++;
		i++;
	}
	return (count);
}

static void	ft_free(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}