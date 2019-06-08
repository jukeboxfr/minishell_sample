/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <kesaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:39:44 by kesaint-          #+#    #+#             */
/*   Updated: 2019/01/28 18:05:24 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		if (n >= -9)
			return (ft_putnbr(-n));
		ft_putnbr(-(n / 10));
		ft_putnbr(-(n % 10));
		return ;
	}
	if (n <= 9)
		return (ft_putchar(n + 48));
	ft_putnbr(n / 10);
	ft_putnbr(n % 10);
}
