/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 12:51:58 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/08 14:02:22 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static int		get_var_len(t_var *var)
{
	return (ft_strlen(var->name) + ft_strlen(var->value) + 1);
}

static char		**copy_env(char **str, int count, t_var *env)
{
	int		size;

	while (env)
	{
		size = get_var_len(env);
		if (!(*str = (char*)ft_memalloc(sizeof(char) * (size + 1))))
			return (NULL);
		ft_strcpy(*str, env->name);
		ft_strcat(*str, "=");
		ft_strcat(*str, env->value);
		str++;
		env = env->next;
	}
	return (str - count);
}

static int		count_env(t_var *env)
{
	int	count;

	count = 0;
	while (env && ++count)
		env = env->next;
	return (count);
}

char			**str_env(t_var *env)
{
	int		count;
	char	**str;

	count = count_env(env);
	if (!(str = (char**)ft_memalloc(sizeof(char*) * (count + 1))))
		return (NULL);
	return (copy_env(str, count, env));
}
