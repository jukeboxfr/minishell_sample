/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 11:43:13 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/08 15:56:28 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void 	exec(t_command *command)
{
	char	*path;

	if (!(path = get_path(command->env, command->argv[0])))
	{
		printf("Une erreur\n");
		return ;
	}
	printf("OK\n");
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
