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


static void			remove_variable(char *str)
{
	char 	*ptr;

	ptr = (str + 1);
	while (*ptr && (ft_isalnum(*ptr) || *ptr == '_'))
		ptr++;
	ft_strcpy(str, ptr);
}

static char 		*get_home_path(t_var *env)
{
	char 			*path;
	struct 	passwd 	*user;;
	uid_t			uid;

	if ((path = get_var(env, "HOME")))
		return (path);
	uid = getuid();
	user = getpwuid(uid);
	return (ft_strdup(user->pw_dir));
}

static void			check_variables(t_var *env, char **argv)
{
	char 	**tab;
	char 	*val;

	tab = argv;
	while (*tab)
	{
		if (**tab == '$' || !ft_strcmp(*tab, "~"))
		{
			val = **tab == '$'
				? get_var(env, *tab + 1)
				: get_home_path(env);
			if (val)
			{
				free(*tab);
				*tab = val;
			}
			else
				remove_variable(*tab);
		}
		tab++;
	}
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
	check_variables(env, command->argv);
	command->argc = 0;
	while (command->argv[command->argc])
		command->argc++;
	return (command);
}
