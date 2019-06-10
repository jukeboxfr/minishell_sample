/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <kesaint-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:07:55 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/10 19:14:42 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	countstr(char const *s, char *search)
{
	int		count;

	count = 0;
	while (*s)
	{
		while (ft_strchr(search, *s))
			s++;
		if (*s && !ft_strchr(search, *s))
			count++;
		while (*s && !ft_strchr(search, *s))
			s++;
	}
	return (count);
}

static int	getlen(char const *s, char *search)
{
	int	len;

	len = 0;
	while (s[len] && !ft_strchr(search, s[len]))
		len++;
	return (len);
}

static int	copy(char **tab, char const *s, char *search)
{
	int		len;

	len = getlen(s, search);
	if (!(*tab = ft_strnew(len)))
		return (0);
	ft_strncpy(*tab, s, len);
	return (len);
}

static char	**free_tab(char **tab, int i)
{
	while (i)
	{
		i--;
		free(tab[i]);
	}
	free(tab);
	return (NULL);
}

char		**ft_sstrsplit(char const *s, char *search)
{
	int		i;
	int		count;
	int		len;
	char	**tab;

	if (!s)
		return (NULL);
	count = countstr(s, search);
	if (!(tab = (char**)malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	i = 0;
	while (*s && i < count)
	{
		while (ft_strchr(search, *s))
			s++;
		if (!(len = copy(tab + i, s, search)))
			return (free_tab(tab, i));
		s += len;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
