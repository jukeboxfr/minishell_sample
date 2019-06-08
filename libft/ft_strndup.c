/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <kesaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:30:08 by kesaint-          #+#    #+#             */
/*   Updated: 2018/11/18 15:33:09 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, int size)
{
	char	*dst;

	dst = (char*)ft_memalloc(sizeof(char) * (size + 1));
	if (dst == NULL)
		return (NULL);
	return (ft_strncpy(dst, s, size));
}
