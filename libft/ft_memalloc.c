/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <kesaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 20:01:40 by kesaint-          #+#    #+#             */
/*   Updated: 2018/11/18 15:29:06 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void		*mem;
	size_t		i;

	if ((mem = (void*)malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		*(char*)(mem + i) = '\0';
		i++;
	}
	return (mem);
}
