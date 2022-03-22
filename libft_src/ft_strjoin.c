/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 21:21:26 by falarm            #+#    #+#             */
/*   Updated: 2021/10/12 21:42:19 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	res = NULL;
	if (s1 && s2)
	{
		res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
		if (!res)
			return (NULL);
		i = 0;
		while (s1[i])
		{
			res[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j])
			res[i++] = s2[j++];
		res[i] = '\0';
	}
	return (res);
}
