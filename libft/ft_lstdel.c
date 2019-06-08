/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <kesaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 21:32:29 by kesaint-          #+#    #+#             */
/*   Updated: 2018/11/24 16:38:20 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*next;

	if (!alst || !del)
		return ;
	next = *alst;
	while (next)
	{
		tmp = next;
		next = tmp->next;
		(*del)(tmp->content, tmp->content_size);
		free(tmp);
	}
	*alst = NULL;
}
