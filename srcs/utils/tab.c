/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:05:17 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/10 16:15:42 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
void	clear_tab(char **tab)
{
	char	**ptr;

	ptr = tab;
	printf("=> %p\n", ptr);
	fflush(stdout);
	while (*ptr)
	{
		printf("->> %s\n", *ptr);
		printf("=>> %p\n", *ptr);
		fflush(stdout);
		free(*ptr);
		ptr++;
	}
	printf("OK\n");
	fflush(stdout);
	free(tab);
}
