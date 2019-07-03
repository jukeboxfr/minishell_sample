/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 11:43:13 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/15 02:11:01 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_home_path(t_var *env)
{
	char			*path;
	struct passwd	*user;
	uid_t			uid;

	if ((path = get_var(env, "HOME")))
		return (path);
	uid = getuid();
	user = getpwuid(uid);
	return (ft_strdup(user->pw_dir));
}

void	exec(t_command *command)
{
	char	*path;

	if (!(path = get_path(command->env, command->argv[0])))
		return ;
	start_process(path, command);
	free(path);
}

int		check_builtin(t_var **envp, t_command *command)
{
	void	(*f)(int, char**, t_var**);

	f = NULL;
	if (!ft_strcmp(command->argv[0], "echo"))
		f = &builtin_echo;
	if (!ft_strcmp(command->argv[0], "cd"))
		f = &builtin_cd;
	if (!ft_strcmp(command->argv[0], "export"))
		f = &builtin_setenv;
	if (!ft_strcmp(command->argv[0], "unset"))
		f = &builtin_unsetenv;
	if (!ft_strcmp(command->argv[0], "env"))
		f = &builtin_env;
	if (f)
	{
		f(command->argc, command->argv, envp);
		return (SUCCESS);
	}
	return (ERROR);
}

void	minishell(t_var **envp)
{
	char		*line;
	t_command	*command;

	g_child_pid = 0;
	line = NULL;
	while (1)
	{
		ft_putstr("$> ");
		if (read_until(&line, '\n', FALSE) < 0)
			return ;
		command = parse_command(*envp, line);
		free(line);
		if (!command)
			continue ;
		command->env = *envp;
		if (!ft_strcmp(command->argv[0], "exit"))
		{
			clear_command(&command);
			return ;
		}
		if (check_builtin(envp, command))
			exec(command);
		clear_command(&command);
	}
}
