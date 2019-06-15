/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 19:45:35 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/10 14:48:34 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

# define NOT_DIR (1 << 0)
# define DENIED (1 << 2)
# define NOT_FOUND (1 << 3)

int			check_directory(char *path, char *base, char *filename);

static void		display_error(int code, char *filename)
{
	ft_putstr("cd: ");
	if (code == NOT_FOUND)
		ft_putstr("no such file or directory: ");
	if (code == DENIED)
		ft_putstr("permission denied: ");
	if (code == NOT_DIR)
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

int			check_directory(char *path, char *base, char *filename)
{
	t_dir		dir;
	t_dirent	*file;
	int			code;

	if (!(dir = opendir(base)))
		return (NOT_DIR);
	code = 0;
	while ((file = readdir(dir)))
	{
		if (ft_strcasecmp(file->d_name, filename))
			continue ;
		if (file->d_type == DT_LNK)
			code = check_symlink(path);
		else if (file->d_type != DT_DIR)
			code = NOT_DIR;
		else if (access(path, R_OK))
			code = DENIED;
		break ;
	}
	closedir(dir);
	if (!file)
		code = NOT_FOUND;
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

static void		change_directory(t_var **envp, char *path)
{
	char	buffer[MAX_PATH + 1];
	char	*old;
	char	*pwd;

	chdir(path);
	if (!(old = get_var(*envp, "PWD")))
		return ;
	edit_var(envp, "OLDPWD", old);
	getcwd(buffer, MAX_PATH);
	if (!(pwd = ft_strdup(buffer)))
		return ;
	edit_var(envp, "PWD", pwd);
}

void			builtin_cd(int argc, char **argv, t_var **envp)
{
	char	*path;

	if (argc < 2)
	{
		if ((path = get_var(*envp, "HOME")))
		{
			change_directory(envp, path);
			free(path);
		}
		return ;
	}
	if (argc > 3)
	{
		puts("Error test\n");
		return ;
	}
	if (fi_not_access(argv[1]))
		return ;
	change_directory(envp, argv[1]);
}
