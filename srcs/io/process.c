/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 17:11:57 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/10 19:17:31 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	start_process(char *path, t_command *command)
{
	char	**env;
	char	*pwd;

	if (!(g_child_pid = fork()))
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
	waitpid(g_child_pid, NULL, 0);
}
