#include "minishell.h"

static t_command	*get_previous_cmd(t_command *command, t_command *previous)
{
	(void)command;
	clear_command(&command);
	return (previous);
}

static t_command	*get_last_word(t_command *command, t_command *previous)
{
	if (previous->argc < 2)
		return (command);
	previous->argv[1] = previous->argv[previous->argc - 1];
	previous->argc = 2;
	previous->env = command->env;
	clear_command(&command);
	return (previous);
}

static t_command	*get_exc_lword(t_command *command, t_command *previous)
{
	if (previous->argc < 2)
		return (command);
	previous->argc--;
	previous->env = command->env;
	ft_memmove((previous->argc + 1), (previous->argv + 2), (previous->argc - 1));
	clear_command(&command);
	return(previous);
}

char				*check_shell_bang(t_command *command, t_command *previous)
{
	char	**args;
	char 	c;

	args = command->argc;
	while (*args)
	{
		if (**args == '!' && *(*args + 1) && !*(args + 2))
		{
			c = *(*args + 1);
			if (c == '!')
					return (get_previous_cmd(command, previous));
			if (c == '$')
				return (get_last_word(command, previous));
			if (c == '*')
				return (get_exc_lword(command, previous));
		}
		args++;
	}
}