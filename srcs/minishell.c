/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 11:43:13 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/08 15:10:43 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	is_exe(mode_t d_type, char *path)
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

static t_bool	check_fi_exists(t_dir dir, char *filename)
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

t_bool			file_exists(char *path, char *filename)
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

char			*get_file_path(t_var *env, const char *filename)
{
	char	*env_path;
	char	**directory_path;
	char	**path;
	char	*executable_path;

	if (!(env_path = get_var(env, "PATH")))
		return (NULL);
	if (!(directory_path = ft_strsplit(env_path, ':')))
		return (NULL);
	executable_path = NULL;
	path = directory_path;
	while (*path)
	{
		if (file_exists(*path, (char*)filename))
		{
			executable_path = join_path(*path, (char*)filename);
			break ;
		}
		path++;
	}
	//clear_tab(directory_path);
	return (executable_path);
}


/*


				[OK]

*/

void	exec(t_command *command)
{
	char	*path;

	if (ft_strchr(command->argv[0], '/'))
	{
		if (file_exists(command->argv[0], NULL))
			path = command->argv[0];
		else
			path = NULL; 
	}
	else
		path = get_file_path(command->env, command->argv[0]);
	printf("Le chemin est %s\n", path);
}

void	minishell(t_var **envp)
{
	char		*line;
	t_command	*command;

	line = NULL;
	while (1)
	{
		ft_putstr("$> ");
		if (read_until(&line, '\n', 0) < 0)
			return ;
		command = parse_command(line);
		free(line);
		if (!command)
			continue ;
		command->env = *envp;
		exec(command);
	}
}
