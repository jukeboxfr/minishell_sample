/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 17:11:57 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/10 14:50:34 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "command.h"
#include "io.h"

void	start_process(char *path, t_command *command)
{
	char	**env;
	int		pid;
	char	*pwd;

	if (!(pid = fork()))
	{
		edit_var(&(command->env), "_", path);
		if ((env = str_env(command->env)))
			execve(path, command->argv, env);
		clear_envp(&(command->env));
		clear_command(&command);
		if (env)
			clear_tab(env);
		exit(1);
	}
	waitpid(pid, NULL, 0);
}
