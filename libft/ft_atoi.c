/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <kesaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:15:46 by kesaint-          #+#    #+#             */
/*   Updated: 2018/11/17 17:24:11 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *nptr)
{
	int				i;
	long long		number;
	int				negative;

	number = 0;
	i = 0;
	while (nptr[i] == 10 || nptr[i] == 32
		|| nptr[i] == 9 || nptr[i] == 12
		|| nptr[i] == 13 || nptr[i] == 11)
		i++;
	negative = (nptr[i] == '-');
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number *= 10;
		number += nptr[i] - '0';
		if (!negative && number < 0)
			return (-1);
		if (negative && -number > 0)
			return (0);
		i++;
	}
	return ((int)(negative ? -number : number));
}
