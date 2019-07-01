/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 12:12:53 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/08 12:15:28 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static char 			*remove_variable(char *str)
{
	char 	*ptr;

	ptr = (str + 1);
	while (*ptr && (ft_isalnum(*ptr) || *ptr == '_'))
		ptr++;
	return (ft_strcpy(str, ptr));
}

static char 			*get_builtin(t_var *env, char c)
{
	if (c == '~')
		return (get_home_path(env));
	return (NULL);
}

static char 			*get_bang(char c)
{
	return (NULL);
}

void					replace_vars(t_var *env, char **argv)
{
	char 	**args;
	char 	*value;

	args = argv;
	while (*args)
	{
		if ((**args && !*(*args + 1))
			|| (*(*args + 1) && (**args == '$' || (**args == '!' && *(*args + 2)))))
		{
			if (**args == '$' && *(*args + 1) == '$' && !*(*args + 2))
				value = ft_itoa(getpid());
			if (**args == '$')
				value = get_var(env, *args + 1);
			else if (**args == '!' && (*(*args + 1)))
				value = get_bang(*(*args + 1));
			else
				value = get_builtin(env, **args);
			if (value)
			{
				free(*args);
				*args = value;
			}
		}
		args++;
	}
}