/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:38:33 by falarm            #+#    #+#             */
/*   Updated: 2021/10/15 19:46:46 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	words_count(char const *s, char c)
{
	int	res;
	int	word;

	res = 0;
	word = 0;
	while (*s)
	{
		if (*s != c && word == 0)
		{
			word = 1;
			res++;
		}
		if (*s == c && word == 1)
			word = 0;
		s++;
	}
	return (res);
}

static size_t	len_word(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static int	free_all(char **s, int i)
{
	if (s[i] == NULL)
	{
		while (i >= 0)
		{
			free(s[i]);
			i--;
		}
		free(s);
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		words;

	if (!s)
		return (NULL);
	words = words_count(s, c);
	res = (char **) malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (*s && i < words)
	{
		while (*s && *s == c)
			s++;
		res[i] = ft_substr(s, 0, len_word(s, c));
		if (free_all(res, i))
			return (NULL);
		while (*s && *s != c)
			s++;
		i++;
	}
	res[i] = NULL;
	return (res);
}
