# include "minishell.h"

static unsigned int 	count_quotes(char *arg)
{
	unsigned int i;
	unsigned int count;

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
	int		size;

	quote = ft_strchr(buffer, '"');
	if (quote && !(quote != args && *(quote - 1) == '\\'))
		qt_pos = (quote - buffer) + 1;
	else
		qt_pos = ft_strlen(buffer);
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