/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 03:42:50 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/15 03:43:16 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static unsigned int			count_quotes(char *arg)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (arg[i])
	{
		if (arg[i] == '"' && (!i || (i && arg[i - 1] != '\\')))
			count++;
		i++;
	}
	return (count);
}

static char				*update_args(char *args, char *buffer)
{
	char	*arg;
	char	*quote;
	int		qt_pos;
	int		args_len;
	int		size;

	quote = ft_strchr(buffer, '"');
	qt_pos = ft_strlen(buffer);
	args_len = ft_strlen(args);
	size = (qt_pos + ft_strlen(args));
	if ((arg = (char*)ft_memalloc(sizeof(char) * (size + 1))))
	{
		ft_strcpy(arg, args);
		ft_strncat(arg, buffer, qt_pos);
	}
	free(args);
	free(buffer);
	return (arg);
}

char					*parse_quotes(char *arg)
{
	char			*buffer;

	while (count_quotes(arg) % 2)
	{
		ft_putstr("dquote> ");
		if (read_until(&buffer, '\n', TRUE) < 0)
			break ;
		if (!(arg = update_args(arg, buffer)))
			return (NULL);
	}
	return (arg);
}

static int					count_args(char *line)
{
	int	count;
	char	*ptr;

	count = 0;
	ptr = line;
	while (*ptr)
	{
		while (*ptr && *ptr == ' ')
			ptr++;
		if ((ptr == line || (*(ptr - 1) != '\\')) && *ptr == '"')
		{
			++ptr;
			while (*ptr && *ptr != '"')
				ptr++;
			if (*ptr == '"')
				count++;
		}
		else if (ptr == line || (*(ptr - 1) == ' ' && *ptr && *ptr != ' '))
		{
			while (*ptr && *ptr != ' ')
				ptr++;
			count++;
		}
		ptr++;
	}
	return (count);
}

static char			*cstr(char *line, char c)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != c)
		i++;
	return (ft_strndup(line, i));
}

void			foo(char **args, char *line)
{
	char	*ptr;

	ptr = line;
	while (*ptr)
	{
		while (*ptr && *ptr == ' ')
			ptr++;
		if ((ptr == line || (*(ptr - 1) != '\\')) && *ptr == '"')
			*args = cstr(++ptr, '"');
		else if (ptr == line || (*ptr - 1) == ' ' && *ptr && *ptr != ' ')
			*args = cstr(ptr, ' ');
		args++;
		ptr++;
	}
}

char				*parse_args(char *line)
{
	char	**args;
	int		count;

	count = count_args(line);
	printf("Le nombre d'arguments est %i\n", count);
	fflush(stdout);
	if (!(args = (char**)ft_memalloc(sizeof(char*) + (count + 1))))
		return (NULL);
	foo(args, line);
	while (*args)
	{
		ft_putstr("Param -> ");
		ft_putstr(*args);
		ft_putchar('\n');
		args++;
	}
	return (NULL);
}
