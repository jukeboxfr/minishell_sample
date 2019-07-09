/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 12:40:30 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/10 15:27:30 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "env.h"

char			*get_var(t_var *env, char *name)
{
	while (env)
	{
		if (!ft_strcmp(env->name, name))
			return (ft_strdup(env->value));
		env = env->next;
	}
	return (NULL);
}

static t_var	*create_var(char *name, char *value)
{
	t_var	*var;

	if (!(var = (t_var*)ft_memalloc(sizeof(t_var))))
		return (NULL);
	if (!(var->name = ft_strdup(name)))
	{
		free(var);
		return (NULL);
	}
	var->value = value;
	return (var);
}

void			edit_var(t_var **envp, char *name, char *value)
{
	t_var	*env;
	t_var	*var;

	env = *envp;
	while (env)
	{
		if (!ft_strcmp(env->name, name))
		{
			free(env->value);
			env->value = value;
			return ;
		}
		env = env->next;
	}
	if (!(var = create_var(name, value)))
		return (free(value));
	append_var(envp, var);
}

void			append_var(t_var **envp, t_var *var)
{
	t_var	*env;

	if (!*envp)
	{
		*envp = var;
		return ;
	}
	env = *envp;
	while (env->next)
		env = env->next;
	env->next = var;
	var->previous = env;
}

void			remove_var(t_var **envp, char *name)
{
	t_var	*var;

	if (!(var = *envp))
		return ;
	if (!var->next && !ft_strcmp(var->name, name))
		return (clear_envp(envp));
	while (*envp && var)
	{
		if (!ft_strcmp(var->name, name))
		{
			if (var->previous)
				var->previous->next = var->next;
			else
				*envp = var->next;
			if (var->next)
				var->next->previous = var->previous;
			var->next = NULL;
			free(var->name);
			free(var->value);
			free(var);
			var = *envp;
			continue ;
		}
		var = var->next;
	}
}
