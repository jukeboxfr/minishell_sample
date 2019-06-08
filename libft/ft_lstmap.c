/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <kesaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 22:19:01 by kesaint-          #+#    #+#             */
/*   Updated: 2018/11/24 17:46:55 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		*lstfree(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->content)
			free(tmp->content);
		tmp = lst->next;
		free(lst);
	}
	return (NULL);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list	*elem))
{
	t_list	*tmp;
	t_list	*new_lst;
	t_list	*it;

	if (!lst || !f)
		return (NULL);
	if (!(new_lst = (*f)(lst)))
		return (NULL);
	lst = lst->next;
	it = new_lst;
	while (lst)
	{
		if (!(tmp = (*f)(lst)))
			return (lstfree(new_lst));
		it->next = tmp;
		it = it->next;
		lst = lst->next;
	}
	return (new_lst);
}
