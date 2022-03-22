/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:55:43 by falarm            #+#    #+#             */
/*   Updated: 2021/10/12 19:20:00 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	ch;
	char	*str;
	size_t	i;

	ch = c;
	str = (char *) s;
	i = 0;
	while (str[i] && i < n)
	{
		if (str[i] == ch)
			return ((void *) &str[i]);
		i++;
	}
	if (str[i] == ch && i < n)
		return ((void *) &str[i]);
	return (NULL);
}
