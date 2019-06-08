/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <kesaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 20:36:20 by kesaint-          #+#    #+#             */
/*   Updated: 2018/11/18 15:28:43 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	void	*copy_content;

	copy_content = NULL;
	if ((list = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content != NULL)
	{
		if ((copy_content = ft_memalloc(content_size)) == NULL)
			return (NULL);
		ft_memcpy(copy_content, content, content_size);
		list->content = copy_content;
		list->content_size = content_size;
	}
	else
	{
		list->content = NULL;
		list->content_size = 0;
	}
	list->next = NULL;
	return (list);
}
