/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 12:18:37 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/08 12:34:19 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static char		*get_var_value(char *str)
{
	char	*ptr;

	ptr = ft_strchr(str, '=');
	return (ft_strdup(++ptr));
}

static char		*get_var_name(char *str)
{
	char	*ptr;
	char	*name;
	int		size;

	ptr = ft_strchr(str, '=');
	size = (ptr - str);
	if (!(name = (char*)ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	return (ft_strncpy(name, str, size));
}

static t_var	*parse_var(char *str)
{
	t_var	*var;

	if (!(var = (t_var*)ft_memalloc(sizeof(t_var))))
		return (NULL);
	if (!(var->name = get_var_name(str)))
	{
		free(var);
		return (NULL);
	}
	if (!(var->value = get_var_value(str)))
	{
		free(var->name);
		free(var);
	}
	return (var);
}
t_var			*parse_envp(char **envp)
{
	t_var		*var;
	t_var		*env;

	env = NULL;
	while (*envp)
	{
		if (!(var = parse_var(*envp)))
		{
			clear_envp(&env);
			break ;
		}
		append_var(&env, var);
		envp++;
	}
	return (env);
}
