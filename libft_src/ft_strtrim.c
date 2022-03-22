/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 21:30:54 by falarm            #+#    #+#             */
/*   Updated: 2021/10/18 17:34:02 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		end;

	res = NULL;
	if (!s1)
		return (NULL);
	else
	{
		while (*s1 && ft_strchr(set, *s1))
			++s1;
		end = ft_strlen(s1);
		while (end && ft_strchr(set, *(s1 + end)))
			--end;
		res = ft_substr(s1, 0, end + 1);
	}
	return (res);
}
