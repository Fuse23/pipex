/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 21:39:31 by falarm            #+#    #+#             */
/*   Updated: 2021/10/18 17:06:46 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	slen;

	slen = ft_strlen(needle);
	if (slen > ft_strlen(haystack))
		return (NULL);
	if (slen == 0 || (!haystack && *haystack))
		return ((char *) haystack);
	if (len)
	{
		while (*haystack && slen <= len)
		{
			if (*haystack == *needle && ft_strncmp(haystack, needle, slen) == 0)
				return ((char *) haystack);
			haystack++;
			len--;
		}
	}
	return (NULL);
}
