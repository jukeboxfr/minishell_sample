/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <kesaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:30:08 by kesaint-          #+#    #+#             */
/*   Updated: 2018/11/18 15:33:09 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		len;
	char	*dst;

	len = 0;
	while (s[len])
		len++;
	dst = (char*)malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	return (ft_strcpy(dst, s));
}
