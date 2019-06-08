/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <kesaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 18:18:52 by kesaint-          #+#    #+#             */
/*   Updated: 2018/11/18 15:28:57 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstpop(t_list *lst)
{
	t_list *tmp;

	if (!lst)
		return ;
	if (!lst->next)
	{
		free(lst);
		return ;
	}
	while (lst)
	{
		tmp = lst->next;
		if (tmp && tmp->next == NULL)
		{
			free(tmp);
			lst->next = NULL;
			return ;
		}
		lst = tmp;
	}
}
