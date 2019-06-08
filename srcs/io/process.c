/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 15:49:36 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/08 15:54:05 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "io.h"

static t_bool			executable(t_dirent *file, char *path)
{
	struct stat		s;
	int				(*f)(const char*, struct stat*);

	if (file->d_type == DT_DIR)
		return (FALSE);
	f = (file->d_type == DT_LNK) ? &stat : &lstat;
	if (f(path, &s))
		return (FALSE);
	return (s.st_mode & S_IXUSR);
}

static char		*foo(char *base, char *filename)
{
	t_dir 		dir;
	t_dirent	*file;
	char		*path;
	int			(*f)(const char*, struct stat*);

	if (!(dir = opendir(base)))
		return (NULL);
	path = NULL;
	while ((file = readdir(dir)))
	{

		if (ft_strcmp(file->d_name, filename))
			continue ;
		if (!(path = join_path(base, filename)))
			break ;
		if (!executable(file, path))
		{
			free(path);
			path = NULL;
		}
		break ;
	}
	closedir(dir);
	return (path);
}

static char 		*get_file_path(char *path, char *filename)
{
	char	*base;

	if (!(path = resolve_path(path)))
		return (NULL);
	if (!filename)
	{
		if (!(base = get_base_path(path)))
			return (NULL);
		filename = get_filename(path);
	}
	else
		base = path;
	return (foo(base, filename));
}

static char				*search_file_path(t_var *env, char *filename)
{
	char	*var;
	char	**directories;
	char	**dir;
	char	*path;

	if (!(var = get_var(env, "PATH")))
		return (NULL);
	if (!(directories = ft_strsplit(var, ':')))
		return (NULL);
	dir = directories;
	path = NULL;
	while (*dir)
	{
		if ((path = get_file_path(*dir, filename)))
			break ;
		dir++;
	}
	return (path);
}

char		*get_path(t_var *env, char *filename)
{
	if (ft_strchr(filename, '/'))
		return (get_file_path(filename, NULL) ? filename : NULL);
	return (search_file_path(env, filename));
}
