/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 14:03:56 by kesaint-          #+#    #+#             */
/*   Updated: 2019/07/03 16:29:08 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	builtin_echo(int argc, char **argv, t_var **envp)
{

	(void)argc;
	(void)envp;
	argv++;
	while (*argv)
	{
		ft_putstr(*argv++);
		if (*argv)
			ft_putchar(' ');
	}
	ft_putchar('\n');
}
