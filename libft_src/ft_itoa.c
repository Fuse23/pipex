/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 16:55:32 by falarm            #+#    #+#             */
/*   Updated: 2021/10/16 20:25:12 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	ft_intlen(int x)
{
	size_t	len;

	len = 0;
	if (x <= 0)
	{
		x = -x;
		len = 1;
	}
	while (x)
	{
		x /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*s;
	size_t		len;
	long int	x;

	x = n;
	len = ft_intlen(x);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	if (x == 0)
		s[0] = '0';
	if (x < 0)
	{
		s[0] = '-';
		x = -x;
	}
	s[len--] = '\0';
	while (x)
	{
		s[len--] = (x % 10) + '0';
		x /= 10;
	}
	return (s);
}
