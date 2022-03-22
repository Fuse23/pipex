/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falarm <falarm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 20:46:00 by falarm            #+#    #+#             */
/*   Updated: 2021/10/12 19:44:02 by falarm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*found;
	char	*tmp;

	ch = c;
	found = NULL;
	if (ch == '\0')
		return (ft_strchr(s, c));
	tmp = ft_strchr(s, c);
	while (tmp != NULL)
	{
		found = tmp;
		s = tmp + 1;
		tmp = ft_strchr(s, c);
	}
	return (found);
}
