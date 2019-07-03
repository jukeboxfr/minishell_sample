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

static t_bool	set_display_opt(int *opts, char opt)
{
	if (opt == 'n')
		*opts |= O_LINES;
	else if (opt == 'e')
		*opts |= O_ALL;
	else
		return (FALSE);
	return (TRUE);
}

static t_bool	set_opts(int *opts, char *opt)
{
	int		i;

	i = 0;
	while (opt[++i])
	{
		if (set_display_opt(opts, opt[i]))
			continue ;
		return (ERROR);
	}
	return (SUCCESS);
}

static int	get_options(char **argv)
{
	int		i;
	int		opts;

	opts = 0;
	i = 1;
	while (*argv)
	{
		if (argv[0] == '-' && argv[1] != '\0')
		{
			if (argv[1] == '-' && argv[2] == '\0')
				break ;
			if (set_opts(&opts, *argv) != SUCCESS)
				return (ERROR);
		}
		argv++;
	}
	return (opts);
}

void		builtin_echo(int argc, char **argv, t_var **envp)
{
	int	i;
	int	options;

	options = get_options(argv);
	(void)argc;
	(void)envp;
	i = 0;
	while (i < argc)
	{
		if (argv[i])
		{
			ft_putstr(*argv[i]);
		}
		i++;
	}
}
