/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstevery.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <kesaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:03:31 by kesaint-          #+#    #+#             */
/*   Updated: 2018/11/24 16:58:32 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstevery(t_list *lst, int (*f)(t_list	*elem))
{
	if (!f)
		return (0);
	while (lst)
	{
		if (!(*f)(lst))
			return (0);
		lst = lst->next;
	}
	return (1);
}
