/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 11:41:31 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/08 11:43:01 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char *argv[], char *envp[])
{
	t_var	*env;

	(void)argc;
	(void)argv;
	if (!(env = (t_var*)parse_envp(envp)))
		return (ERROR);
	minishell(&env);
	clear_envp(&env);
	return (0);
}
