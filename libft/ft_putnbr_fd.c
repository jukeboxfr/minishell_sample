/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <kesaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:57:11 by kesaint-          #+#    #+#             */
/*   Updated: 2018/11/15 16:50:25 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		if (n >= -9)
			return (ft_putnbr_fd(-n, fd));
		ft_putnbr_fd(-(n / 10), fd);
		ft_putnbr_fd(-(n % 10), fd);
		return ;
	}
	if (n <= 9)
		return (ft_putchar_fd(n + 48, fd));
	ft_putnbr_fd(n / 10, fd);
	ft_putnbr_fd(n % 10, fd);
}
