/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhabib <rhabib@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:10:12 by rhabib            #+#    #+#             */
/*   Updated: 2015/12/09 12:09:12 by rhabib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t i2;
	size_t s2len;

	s2len = ft_strlen(s2);
	if (s2len == 0)
		return ((char *)s1);
	i = 0;
	while (s1[i] && i < n)
	{
		i2 = 0;
		while (s2[i2] && i + i2 < n)
		{
			if (s1[i + i2] != s2[i2])
				break ;
			i2++;
		}
		if (i2 == s2len)
			return ((char *)(s1 + i));
		i++;
	}
	return (NULL);
}
