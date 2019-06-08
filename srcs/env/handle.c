/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 12:40:30 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/08 13:52:29 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*get_var(t_var *env, char *name)
{
	while (env)
	{
		if (!ft_strcmp(env->name, name))
			return (ft_strdup(env->value));
		env = env->next;
	}
	return (NULL);
}

void	edit_var(t_var *env, char *name, char *value)
{
	while (env)
	{
		if (ft_strcmp(name, value))
			env = env->next;
		free(env->value);
		env->value = value;
		return ;
	}
}

void	append_var(t_var **envp, t_var *var)
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
}

void	remove_var(t_var **envp, char *name)
{
	t_var	*var;

	if (!(var = *envp))
		return ;
	if (!var->next && !ft_strcmp(var->name, name))
		return (clear_envp(envp));
	while (*envp && var->next)
	{
		if (!ft_strcmp(var->name, name))
		{
			if (var->previous)
				var->previous->next = var->next;
			else
				*envp = var->next;
			var->next->previous = var->previous;
			var->next = NULL;
			var = *envp;
			continue ;
		}
		var = var->next;
	}
}
