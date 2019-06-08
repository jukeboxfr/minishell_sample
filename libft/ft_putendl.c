/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <kesaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 21:20:43 by kesaint-          #+#    #+#             */
/*   Updated: 2018/11/18 15:30:41 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_putendl(char const *s)
{
	if (s == NULL)
		return ;
	ft_putstr(s);
	ft_putchar('\n');
}
