/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 11:56:53 by kesaint-          #+#    #+#             */
/*   Updated: 2019/07/03 16:28:15 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "command.h"
#include "utils.h"

static char					*get_cmd_end_ptr(char *str)
{
	while (*str)
	{
			while (*str == '\\' && *(str + 1) == ';')
					str += 2;
			if (*str == ';')
					return (str);
			str++;
	}
	return (str);
}

static t_command			*create_command(t_var *env, char *str)
{
	t_command	*command;

	if (!(command = (t_command*)ft_memalloc(sizeof(t_command))))
		return (NULL);
	if (!(command->argv = (char**)ft_sstrsplit(str, " \t")))
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

static void					append_command(t_command **list, t_command *next)
{
	t_command	*last;

	if (!*list)
	{
		*list = next;
		return ;
	}
	last = *list;
	while (last->next)
		last = last->next;
	last->next = next;
}

static int					check_ptr(char **ptr)
{
	while (**ptr == '\\' && *(*ptr + 1) == ';')
		*ptr += 2;
	while (**ptr == ';' || **ptr == ' ')
		(*ptr)++;
	return (**ptr);
}

t_command				**split_commands(t_var *env, char *line)
{
	char			*ptr;
	char			*end;
	char			c;
	t_command		*command;
	t_command		*commands;

	commands = NULL;
	ptr = line;
	while (check_ptr(&ptr))
	{
		end = get_cmd_end_ptr(ptr);
		c = *end;
		*end = '\0';
		if (!(command = create_command(env, ptr)))
		{
			clear_command(&commands);
			break ;
		}
		append_command(&commands, command);
		ptr = c ? (end + 1) : end;
	}
	return (commands);
}