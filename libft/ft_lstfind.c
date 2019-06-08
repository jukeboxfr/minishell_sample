/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <kesaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:12:56 by kesaint-          #+#    #+#             */
/*   Updated: 2018/11/24 16:40:25 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstfind(t_list *lst, int (*f)(t_list *elem))
{
	if (!f)
		return (NULL);
	while (lst)
	{
		if ((*f)(lst))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
