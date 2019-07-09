/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 14:04:08 by kesaint-          #+#    #+#             */
/*   Updated: 2019/07/09 14:42:09 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static t_bool	is_valid_input(char *start, char *end)
{
	end--;
	while (end != start)
	{
		if (!ft_isalnum(*end) && *end != '_')
			return (FALSE);
		end--;
	}
	return (TRUE);
}

static void		set_env_vars(char *argv[], t_var **envp)
{
	char	*ptr;
	char	*value;
	char	c;

	argv++;
	while (*argv)
	{
		if ((ptr = ft_strchr(*argv, '=')) && is_valid_input(*argv, ptr))
		{
			c = *ptr;
			*ptr = '\0';
			if (!(value = ft_strdup(ptr + 1)))
			{
				*ptr = c;
				return ;
			}
			edit_var(envp, *argv, value);
			*ptr = c;
		}
		argv++;
	}
}

void			builtin_env(int argc, char **argv, t_var **envp)
{
	t_var	*env;

	(void)argc;
	(void)envp;
	set_env_vars(argv, envp);
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
