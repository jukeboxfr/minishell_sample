/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 12:35:00 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/08 12:38:08 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	clear_var(t_var *var)
{
	free(var->name);
	free(var->value);
	free(var);
}

void	clear_envp(t_var **envp)
{
	t_var	*env;
	t_var	*next;

	env = *envp;
	while (env)
	{
		next = env->next;
		clear_var(env);
		env = next;
	}
	*envp = NULL;
}
