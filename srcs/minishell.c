/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 11:43:13 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/08 12:15:00 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		if (!(command = parse_command(line)))
		{
			free(line);
			continue ;
		}
		command->env = *envp;
	}
}
