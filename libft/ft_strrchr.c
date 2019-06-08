/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <kesaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 15:36:12 by kesaint-          #+#    #+#             */
/*   Updated: 2018/11/18 15:37:35 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	char *ptr;

	ptr = NULL;
	while (42)
	{
		if (*s == c)
			ptr = (char*)s;
		if (!(*s))
			break ;
		s++;
	}
	return (ptr);
}
