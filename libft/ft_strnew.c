/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <kesaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:19:40 by kesaint-          #+#    #+#             */
/*   Updated: 2018/11/18 15:35:25 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "string.h"

char	*ft_strnew(size_t size)
{
	char *mem;

	if ((mem = (char*)ft_memalloc(size + 1)) == NULL)
		return (NULL);
	return (mem);
}
