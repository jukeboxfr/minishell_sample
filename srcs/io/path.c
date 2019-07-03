/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 15:49:36 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/10 19:17:20 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "io.h"

static t_bool	executable(t_dirent *file, char *path)
{
	struct stat		s;
	int				(*f)(const char*, struct stat*);

	if (file->d_type == DT_DIR)
	{
		ft_putstr("minishell: ");
		ft_putstr(path);
		ft_putstr(": is a directory\n");
		return (FALSE);
	}
	f = (file->d_type == DT_LNK) ? &stat : &lstat;
	if (f(path, &s))
		return (FALSE);
	if (!(s.st_mode & S_IXUSR))
	{
		ft_putstr("minishell: ");
		ft_putstr(path);
		ft_putstr(": Permission denied\n");
	}
	return (s.st_mode & S_IXUSR);
}

static char		*search_file(char *base, char *filename, int *count)
{
	t_dir		dir;
	t_dirent	*file;
	char		*path;
	int			(*f)(const char*, struct stat*);

	if (!(dir = opendir(base)))
		return (NULL);
	path = NULL;
	while ((file = readdir(dir)))
	{
		if (ft_strcasecmp(file->d_name, filename))
			continue ;
		(*count)++;
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

static char		*get_file_path(char *path, char *filename, int *count)
{
	char	*base;
	char	*file_path;

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
	file_path = search_file(base, filename, count);
	free(path);
	if (base != path)
		free(base);
	return (file_path);
}

static char		*search_file_path(t_var *env, char *filename)
{
	char	*var;
	char	**directories;
	char	**dir;
	char	*path;
	int 	count;

	if (!(var = get_var(env, "PATH")))
		return (NULL);
	directories = ft_sstrsplit(var, ":;");
	free(var);
	if (!(dir = directories))
		return (NULL);
	path = NULL;
	count = 0;
	while (*dir)
	{
		if ((path = get_file_path(*dir, filename, &count)))
			break ;
		dir++;
	}
	if (!count)
	{
		ft_putstr("minishell: ");
		ft_putstr(filename);
		ft_putstr(": command not found\n");
	}
	clear_tab(directories);
	return (path);
}

char			*get_path(t_var *env, char *filename)
{
	char	*path;
	int		count;

	count = 0;
	if (ft_strchr(filename, '/'))
	{
		if ((path = get_file_path(filename, NULL, &count)))
			return (path);
		if (!count)
		{
			ft_putstr("minishell: ");
			ft_putstr(filename);
			ft_putstr(": command not found\n");
		}
		return (NULL);
	}
	return (search_file_path(env, filename));
}
