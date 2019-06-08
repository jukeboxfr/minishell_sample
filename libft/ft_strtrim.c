/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <kesaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:36:58 by kesaint-          #+#    #+#             */
/*   Updated: 2018/11/18 15:37:06 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int		is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char			*ft_strtrim(char const *s)
{
	size_t	min;
	size_t	max;

	if (!s)
		return (NULL);
	min = 0;
	max = ft_strlen(s);
	while (s[min] && is_whitespace(s[min]))
		min++;
	while (s[max - 1] && is_whitespace(s[max - 1]))
		max--;
	if (min > max)
		return (ft_strsub(s, min, min + 1));
	return (ft_strsub(s, min, max - min));
}
