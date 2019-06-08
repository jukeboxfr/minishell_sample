/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsome.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <kesaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:11:14 by kesaint-          #+#    #+#             */
/*   Updated: 2018/11/24 16:59:50 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsome(t_list *lst, int (*f)(t_list	*elem))
{
	if (!f)
		return (0);
	while (lst)
	{
		if ((*f)(lst))
			return (1);
		lst = lst->next;
	}
	return (0);
}
