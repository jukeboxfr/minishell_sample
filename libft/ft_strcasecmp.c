/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <kesaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:08:18 by kesaint-          #+#    #+#             */
/*   Updated: 2019/05/31 19:44:26 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcasecmp(char *s1, char *s2)
{
	char	c1;
	char	c2;

	while (*s1)
	{
		c1 = *s1;
		c2 = *s2;
		if (c1 >= 'A' && c1 <= 'Z')
			c1 += 32;
		if (c2 >= 'A' && c2 <= 'Z')
			c2 += 32;
		if (c1 != c2)
			break ;
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
