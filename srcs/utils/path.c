/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 19:22:27 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/08 14:59:59 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_bool				is_root(char *path)
{
	return (path[0] == '.' && (!path[1] || (path[1] == '.' && !path[2])));
}

char				*join_path(char *path, char *filename)
{
	size_t	path_len;
	size_t	size;
	t_bool	bs;
	char	*str;

	if (is_root(filename))
		return (ft_strdup(path));
	size = ft_strlen(filename);
	path_len = ft_strlen(path);
	bs = (path[path_len - 1] == '/');
	if (!bs)
		size++;
	size += path_len;
	if (!(str = (char*)ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_strcpy(str, path);
	if (!bs)
		str[path_len] = '/';
	return (ft_strcat(str, filename));
}

char				*resolve_path(char *str)
{
	size_t	size;
	char	*path;

	if (str[0] == '/'
			|| ((str[0] == '.')
				&& (!str[1] || str[1] == '/' || (str[1] == '.'
						&& (!str[2] || str[2] == '/')))))
		return (ft_strdup(str));
	size = ft_strlen(str) + 3;
	if (!(path = (char*)ft_memalloc(sizeof(char) * size)))
		return (NULL);
	ft_strcpy(path, "./");
	ft_strcat(path, str);
	return (path);
}

char				*get_base_path(char *str)
{
	char	*path;
	char	*ptr;
	size_t	size;

	if ((str[0] == '.')
			&& (!str[1]
				|| (str[1] == '.' && !str[2])))
		return (ft_strdup(str));
	size = 0;
	ptr = str;
	while (*ptr)
	{
		if (*ptr == '/')
			size = (ptr - str);
		ptr++;
	}
	return (size ? ft_strndup(str, size)
			: ft_strdup("/"));
}

char				*get_filename(char *str)
{
	char	*ptr;

	ptr = NULL;
	while (*str)
	{
		if (*str == '/')
			ptr = str;
		str++;
	}
	if (!ptr)
		ptr = str;
	*ptr == '/' ? ++ptr : ptr;
	return (*ptr == '/' ? ++ptr : ptr);
}
