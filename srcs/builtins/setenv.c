/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 14:04:48 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/10 19:17:57 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "builtins.h"

static char	*get_var_name(char *arg)
{
	char	*eq;
	int		size;
	char	*str;

	if (!(eq = ft_strchr(arg, '=')))
		return (NULL);
	size = (eq - arg);
	if (!(str = (char*)ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	return (ft_strncpy(str, arg, size));
}

static char	*get_var_value(char *arg)
{
	while (*arg && *arg != '=')
		arg++;
	if (*arg != '=')
		return (NULL);
	return (ft_strdup(arg + 1));
}

void		builtin_setenv(int argc, char **argv, t_var **envp)
{
	char	*name;
	char	*value;

	if (argc < 2)
		return (ft_putstr("Missing arguments\n"));
	if (!(name = get_var_name(argv[1])))
		return ;
	if (!(value = get_var_value(argv[1])))
	{
		free(name);
		return ;
	}
	edit_var(envp, name, value);
}
