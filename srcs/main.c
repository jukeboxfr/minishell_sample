/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 11:41:31 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/10 14:49:54 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init(t_var **envp)
{
	char	buffer[MAX_PATH + 1];
	char	*path;

	if (!getcwd(buffer, MAX_PATH))
		return ;
	if (!(path = ft_strdup(buffer)))
		return ;
	edit_var(envp, "SHELL", path);
}

int		main(int argc, char *argv[], char *envp[])
{
	t_var	*env;

	(void)argc;
	(void)argv;
	if (!(env = (t_var*)parse_envp(envp)))
		return (ERROR);
	init(&env);
	minishell(&env);
	clear_envp(&env);
	return (0);
}
