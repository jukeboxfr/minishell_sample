/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 14:03:56 by kesaint-          #+#    #+#             */
/*   Updated: 2019/07/09 14:18:05 by kesaint-         ###   ########.fr       */
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

static int		get_options(char **argv)
{
	int		i;
	int		opts;

	opts = 0;
	i = 1;
	while (*argv)
	{
		if (*argv[0] == '-' && *argv[1] != '\0')
		{
			if (*argv[1] == '-' && *argv[2] == '\0')
				break ;
			if (set_opts(&opts, *argv) != SUCCESS)
				return (ERROR);
			*argv = NULL;
		}
		argv++;
	}
	return (opts);
}

static void		eval(char *str, int *opts)
{
	char	*ptr;

	ptr = str;
	while (*ptr)
	{
		if (*ptr == '\\' && ft_strchr("abcfnrtv\\", *(ptr + 1)))
		{
			if (*(ptr + 1) == 'a' || *(ptr + 1) == 'b')
				ft_putchar(*(ptr + 1) == 'a' ? '\a' : '\b');
			else if (*(ptr + 1) == 'c')
				*opts |= O_LINES;
			else if (*(ptr + 1) == 'f')
				ft_putchar('\f');
			else if (*(ptr + 1) == 'n' || *(ptr + 1) == 'r')
				ft_putchar(*(ptr + 1) == 'n' ? '\n' : '\r');
			else if (*(ptr + 1) == 't' || *(ptr + 1) == 'v')
				ft_putchar(*(ptr + 1) == 't' ? '\t' : '\v');
			else if (*(ptr + 1) == '\\')
				ft_putchar('\\');
			ptr += 2;
		}
		else
			ft_putchar(*ptr++);
	}
}

void			builtin_echo(int argc, char **argv, t_var **envp)
{
	int	i;
	int	j;
	int	options;

	options = get_options(argv);
	(void)envp;
	i = 1;
	j = 0;
	while (i < argc)
	{
		if (j)
			ft_putchar(' ');
		if (argv[i])
		{
			(options & O_ALL) == O_ALL
				? eval(argv[i], &options) : ft_putstr(argv[i]);
			j++;
		}
		i++;
	}
	if ((options & O_LINES) != O_LINES)
		ft_putchar('\n');
}
