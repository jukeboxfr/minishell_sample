/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 14:04:08 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/10 19:24:21 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	builtin_env(int argc, char **argv, t_var **envp)
{
	t_var	*env;

	(void)argc;
	(void)envp;
	env = *envp;
	while (env)
	{
		ft_putstr(env->name);
		ft_putchar('=');
		ft_putstr(env->value);
		ft_putchar('\n');
		env = env->next;
	}
}
