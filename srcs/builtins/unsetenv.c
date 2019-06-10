/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 14:05:04 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/10 15:10:50 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "builtins.h"

void	builtin_unsetenv(int argc, char **argv, t_var **envp)
{
	if (argc < 2)
		return (ft_putstr("unset: not enough arguments\n"));
	argv++;
	while (*argv)
		remove_var(envp, *argv++);
}
