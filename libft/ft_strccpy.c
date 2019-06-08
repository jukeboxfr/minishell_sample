/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <kesaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:06:33 by kesaint-          #+#    #+#             */
/*   Updated: 2018/11/18 15:32:33 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strccpy(char *dest, const char *str, const char delimiter)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != delimiter)
	{
		dest[i] = str[i];
		i++;
	}
	return (dest);
}
