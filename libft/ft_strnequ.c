/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <kesaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:17:10 by kesaint-          #+#    #+#             */
/*   Updated: 2018/11/18 15:35:15 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!s1 && !s2)
		return (1);
	if (!s1 || !s2)
		return (0);
	while ((*s1 || *s2) && i < n)
	{
		if (*s1 != *s2)
			return (0);
		i++;
		s1++;
		s2++;
	}
	return (1);
}
