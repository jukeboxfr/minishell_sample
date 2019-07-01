/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:07:21 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/08 18:08:33 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H

# include <stdio.h>
# include <sys/stat.h>
# include <unistd.h>
# include <sys/types.h>
# include <dirent.h>
# include <unistd.h>

# include "types.h"
# include "libft.h"
# include "utils.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define BUFF_SIZE 4096

# define MAX_PATH 255

typedef DIR*			t_dir;
typedef struct dirent	t_dirent;
typedef int				t_bool;

int						read_until(char **line, char c, int keep);
void					start_process(char *path, t_command *command);
char					*get_path(t_var *env, char *filename);

int						g_child_pid;

#endif
