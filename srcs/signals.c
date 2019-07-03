/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 16:37:08 by kesaint-          #+#    #+#             */
/*   Updated: 2019/07/01 16:37:29 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		signal_handler(int sig)
{
	if (sig == SIGINT && g_child_pid != -1)
	{
		if (kill(g_child_pid, SIGINT) == ERROR)
			return ;
		else
			g_child_pid = -1;
	}
}

void			listen_signals(void)
{
	signal(SIGINT, signal_handler);
}
