/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 11:43:13 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/08 19:27:21 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	if (!ft_strcmp(command->argv[0], "cd"))
		return (builtin_cd(command->argc, command->argv, envp));
	return (ERROR);
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
