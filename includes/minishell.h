/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 11:58:01 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/15 02:09:27 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <sys/types.h>
#include <signal.h>

# include "types.h"
# include "utils.h"
# include "io.h"
# include "env.h"
# include "command.h"
# include "builtins.h"

char			*check_shell_bang(t_command *command, t_command *previous);

void			display_stderr(char *arg, char *msg);

void			listen_signals(void);
void			minishell(t_var **envp);
char			*parse_args(char *line);

#endif
