/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 17:11:57 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/08 17:12:29 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "command.h"
#include "io.h"

void	start_process(char *path, t_command *command)
{
	char	**env;
	int		pid;	

	if (!(env = str_env(command->env)))
		return ;
	if (!(pid = fork()))
	{
		execve(path, command->argv, env);
		free(path);
		clear_envp(&(command->env));
		clear_command(&command);
		clear_tab(env);
		exit(1);
	}
	clear_tab(env);
	waitpid(pid, NULL, 0);
}