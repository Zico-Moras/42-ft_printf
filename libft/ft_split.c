/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francima <francima@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 06:37:43 by francima          #+#    #+#             */
/*   Updated: 2024/06/22 06:37:44 by francima         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wordscounter(const char *s, char c)
{
	size_t	i;
	size_t	counter;
	int		flag;

	flag = 0;
	counter = 0;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) != c && flag == 0)
		{
			counter++;
			flag = 1;
		}
		if (*(s + i) == c)
			flag = 0;
		i++;
	}
	return (counter);
}

static size_t	contaletras(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**ss;

	if (!s)
		return (0);
	ss = (char **)malloc(sizeof(char *) * (wordscounter(s, c) + 1));
	if (!ss)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			ss[i++] = ft_substr(s, 0, contaletras(s, c));
		while (*s && *s != c)
			s++;
	}
	ss[i] = 0;
	return (ss);
}
