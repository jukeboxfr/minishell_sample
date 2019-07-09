/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 19:45:35 by kesaint-          #+#    #+#             */
/*   Updated: 2019/07/09 14:21:10 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		display_error(int code, char *filename)
{
	ft_putstr("cd: ");
	if (code == ERR_NOT_FOUND)
		ft_putstr("no such file or directory: ");
	if (code == ERR_DENIED)
		ft_putstr("permission denied: ");
	if (code == ERR_NOT_DIR)
		ft_putstr("not a directory: ");
	ft_putstr(filename);
	ft_putchar('\n');
}

static int		check_symlink(char *path)
{
	char	buffer[MAX_PATH + 1];
	char	*base;
	char	*filename;
	int		code;

	if (readlink(path, buffer, MAX_PATH) == ERROR)
		return (ERROR);
	if (*path == '/' && buffer[0] != '/')
		path = join_path("/", buffer);
	else
		path = resolve_path(buffer);
	if (!path)
		return (ERROR);
	if (!(base = get_base_path(path)))
	{
		free(path);
		return (ERROR);
	}
	filename = get_filename(path);
	code = check_directory(path, base, *filename ? filename : ".");
	free(base);
	free(path);
	return (code);
}

int				check_directory(char *path, char *base, char *filename)
{
	t_dir		dir;
	t_dirent	*file;
	int			code;

	if (!(dir = opendir(base)))
		return (ERR_NOT_DIR);
	code = 0;
	while ((file = readdir(dir)))
	{
		if (ft_strcasecmp(file->d_name, filename))
			continue ;
		if (file->d_type == DT_LNK)
			code = check_symlink(path);
		else if (file->d_type != DT_DIR)
			code = ERR_NOT_DIR;
		else if (access(path, R_OK))
			code = ERR_DENIED;
		break ;
	}
	closedir(dir);
	if (!file)
		code = ERR_NOT_FOUND;
	return (code);
}

static int		fi_not_access(char *arg)
{
	char	*path;
	char	*base;
	char	*filename;
	int		code;

	if (!(path = resolve_path(arg)))
		return (ERROR);
	if (!(base = get_base_path(path)))
	{
		free(path);
		return (ERROR);
	}
	filename = get_filename(path);
	if ((code = check_directory(path, base, *filename ? filename : ".")))
		display_error(code, arg);
	free(path);
	free(base);
	return (code);
}

void			builtin_cd(int argc, char **argv, t_var **envp)
{
	char	*path;

	if (argc > 2)
		return (ft_putstr("cd: too many arguments\n"));
	if (argc < 2)
	{
		if (!(path = get_home_path(*envp)))
			return ;
		change_directory(envp, path);
		return (free(path));
	}
	path = argv[1];
	if (argv[1][0] == '-' && !argv[1][1])
		path = get_var(*envp, "OLDPWD");
	if (!path)
		return (display_stderr("cd", "OLDPWD not set"));
	if (!fi_not_access(path))
		change_directory(envp, path);
	if (path != argv[1])
		free(path);
}
