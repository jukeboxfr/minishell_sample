/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 11:56:53 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/08 19:27:12 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "utils.h"

void				clear_command(t_command **command_p)
{
	clear_tab((*command_p)->argv);
	free(*command_p);
	*command_p = NULL;
}

t_command			*parse_command(t_var *env, char *str)
{
	t_command	*command;
	int			count;

	if (!(command = (t_command*)ft_memalloc(sizeof(t_command))))
		return (NULL);
	if (!(command->argv = (char**)ft_strsplit(str, ' ')))
	{
		free(command->argv);
		return (NULL);
	}
	replace_vars(env, command->argv);
	command->argc = 0;
	while (command->argv[command->argc])
		command->argc++;
	return (command);
}
