/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <kesaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:01:34 by kesaint-          #+#    #+#             */
/*   Updated: 2018/11/18 15:33:42 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	srclen;
	size_t	destlen;
	size_t	i;
	size_t	j;

	srclen = ft_strlen(src);
	destlen = ft_strlen(dest);
	i = 0;
	while (dest[i] && i < size)
		i++;
	j = i;
	if (destlen < size)
	{
		while (*src && j < size - 1)
		{
			dest[j] = *src;
			src++;
			j++;
		}
		dest[j] = '\0';
	}
	if (j < size)
		return (srclen + destlen);
	return (i + srclen);
}
