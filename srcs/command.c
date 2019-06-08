/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 11:56:53 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/08 12:10:36 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"

void				clear_command(t_command **command_p)
{
	t_command	*command;

	command = *command_p;
	if (command->argv)
	{
		while (command->argc--)
			free((command->argv + command->argc));
		free(command->argv);
	}
	free(command);
	*command_p = NULL;
}

static int			count_argv(char **argv)
{
	int	count;

	count = 0;
	while (argv[count])
		count++;
	return (count);
}

t_command			*parse_command(char *str)
{
	t_command 	*command;

	if (!(command = (t_command*)ft_memalloc(sizeof(t_command))))
		return (NULL);
	if (!(command->argv = (char**)ft_strsplit(str, ' ')))
	{
		free(command->argv);
		return (NULL);
	}
	command->argc = count_argv(command->argv);
	return (command);
}
