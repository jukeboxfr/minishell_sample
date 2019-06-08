/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <kesaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:49:45 by kesaint-          #+#    #+#             */
/*   Updated: 2018/11/18 15:34:36 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strnchr(const char *s, size_t count, int c)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	ptr = NULL;
	while (*s && i < count)
	{
		if (*s == c)
			ptr = (char*)(s);
		s++;
		i++;
	}
	return (ptr);
}
