/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <kesaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:09:34 by kesaint-          #+#    #+#             */
/*   Updated: 2018/11/18 15:27:28 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static int	numberlen(int n)
{
	int				len;
	unsigned int	tmp;

	if (n == 0)
		return (1);
	len = 0;
	tmp = n;
	if (n < 0)
	{
		tmp = -tmp;
		len = 1;
	}
	while (tmp)
	{
		len++;
		tmp /= 10;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int				len;
	unsigned int	tmp;
	int				max;
	char			*str;

	len = numberlen(n);
	if (!(str = ft_strnew(len)))
		return (NULL);
	max = 0;
	if (n < 0)
	{
		str[0] = '-';
		max++;
	}
	tmp = n < 0 ? -n : n;
	while (len > max)
	{
		str[len - 1] = (tmp % 10) + 48;
		tmp /= 10;
		len--;
	}
	return (str);
}
