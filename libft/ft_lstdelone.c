/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <kesaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 21:03:34 by kesaint-          #+#    #+#             */
/*   Updated: 2018/11/24 17:04:20 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list **alst, void (*del) (void*, size_t))
{
	if (!alst || !del)
		return ;
	(*del)((*alst)->content, ((*alst)->content_size));
	free(*alst);
	*alst = NULL;
}
