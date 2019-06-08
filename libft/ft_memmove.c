/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <kesaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:38:54 by kesaint-          #+#    #+#             */
/*   Updated: 2018/11/24 17:39:09 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*source;
	size_t	i;

	if (!dst && !src)
		return (NULL);
	dest = (char*)dst;
	source = (char*)src;
	if (dest <= source)
	{
		i = 0;
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	}
	else
		while ((int)(--len) >= 0)
			dest[len] = source[len];
	return (dst);
}
