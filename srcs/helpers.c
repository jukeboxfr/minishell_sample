/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 17:25:37 by kesaint-          #+#    #+#             */
/*   Updated: 2019/07/03 17:25:43 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		display_stderr(char *arg, char *msg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(msg, 2);
	ft_putchar_fd('\n', 2);
}

void		clear_command(t_command **command_p)
{
	t_command	*current;
	t_command	*next;

	next= *command_p;
	while ((current = next))
	{
		next = current->next;
		free(current);
		clear_tab(current->argv);
	}
	*command_p = NULL;
}

void		eval_prompt(char *ps1)
{
	while (*ps1)
	{
		if (!ft_strncmp(ps1, "\\033", 3))
		{
			ft_putchar('\033');
			ps1 += 3;
			continue ;
		}
		if (*ps1 == '\\' && *(ps1 + 1))
			ps1++;
		ft_putchar(*ps1);
		ps1++;
	}
}