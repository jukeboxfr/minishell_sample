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

static t_bool			is_exe(mode_t d_type, char *path)
{
	struct stat		s;
	int				(*f)(const char*, struct stat*);

	if (d_type != DT_DIR && d_type != DT_LNK)
		return (FALSE);
	f = (d_type == DT_DIR) ? &stat : &lstat;
	if (f(path, &s))
		return (FALSE);
	return (s.st_mode & S_IXUSR);
}

static t_bool			check_fi_exists(t_dir dir, char *filename)
{
	t_dirent	*file;

	while ((file = readdir(dir)))
	{
		if (ft_strcmp(file->d_name, filename))
			continue ;
		closedir(dir);
		return (TRUE);
	}
	closedir(dir);
	return (FALSE);
}

static t_bool			file_exists(char *path, char *filename)
{
	char		*base;
	t_dir		dir;
	t_bool		exists;

	if (!(path = resolve_path(path)))
		return (FALSE);
	if (!filename)
	{
		if (!(base = get_base_path((char*)path)))
			return (FALSE);
		if (!(filename = get_filename((char*)path)))
		{
			free(base);
			return (FALSE);
		}
	}
	else
		base = (char*)path;
	exists = FALSE;
	if ((dir = opendir(base)))
		exists = check_fi_exists(dir, filename);
	if (!filename)
		free(base);
	return (exists);
}

static char				*get_file_path(t_var *env, const char *filename)
{
	char	*var;
	char	**directories;
	char	**path;

	if (!(var = get_var(env, "PATH")))
		return (NULL);
	if (!(directories = ft_strsplit(var, ':')))
		return (NULL);
	path = directories;
	while (*path)
	{
		if (file_exists(*path, (char*)filename))
			return (join_path(*path, (char*)filename));
		path++;
	}
	return (NULL);
}

char		*get_path(t_var *env, char *filename)
{
	if (ft_strchr(filename, '/'))
		return (file_exists(filename, NULL) ? filename : NULL);
	return (get_file_path(env, filename));
}
