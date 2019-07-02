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

static char 			*replace_home_var(t_var *env, char 	**argv)
{
	char	*path;
	char	*arg;

	if (!(path = get_home_path(env)))
		return (*argv);
	if (!(arg = ft_strjoin(path, *argv + 1)))
	{
		free(path);
		return (*argv);
	}
	free(*argv);
	*argv = arg;
	return (*argv);
}

static char 	*insert_value(char **argv, char *value_ptr, char *after_ptr)
{
	int		size;
	char	*arg;

	size = ft_strlen(*argv);
	if (value_ptr)
		size += ft_strlen(value_ptr);
	size += ft_strlen(after_ptr);
	if (!(arg = (char*)ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_strcpy(arg, *argv);
	if (value_ptr)
		ft_strcat(arg, value_ptr);
	ft_strcat(arg, after_ptr);
	free(*argv);
	*argv = arg;
	return (arg);
}

static char		*replace_var(t_var *env, char **argv, char *start_ptr)
{
	char	*end_ptr;
	char	*value;
	char	c;
	char	*offset;

	off = *argv;
	end_ptr = (start_ptr + 1);
	while (*end_ptr && (ft_isalnum(*end_ptr) || *end_ptr == '_'
		|| (*end_ptr == '$' && end_ptr == (start_ptr + 1))))
		end_ptr++;
	c = *end_ptr;
	*end_ptr = '\0';
	value =  *(start_ptr + 1) == '$' && !*(start_ptr + 2)
		? ft_itoa(getpid()) : get_var(env, (start_ptr + 1));
	*end_ptr = c;
	c = *start_ptr;
	*start_ptr = '\0';
	if (!(insert_value(argv, value, end_ptr)))
		*start_ptr = c;
	offset = *argv + (start_ptr - offset)
		+ (value ? ft_strlen(value) : 0);
	if (value)
		free(value);
	return (offset);
}

void 		replace_vars(t_var *env, char **argv)
{
	char 	*arg;

	while ((arg = *argv))
	{
		if (*arg == '~')
			arg = replace_home_var(env, argv);
		while (*arg)
		{
			while (*arg == '\\' && *(arg + 1) == '$')
			{
				ft_strcpy(arg, (arg + 1));
				arg++;
			}
			if (*arg == '$' && *(arg + 1))
				arg = replace_var(env, argv, arg);
			else
				arg++;
		}
		argv++;
	}
}