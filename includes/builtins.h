/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 12:16:45 by kesaint-          #+#    #+#             */
/*   Updated: 2019/07/05 15:25:02 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "command.h"
# include "io.h"
# include "types.h"

# define O_ALL (1 << 0)
# define O_LINES (1 << 1)

# define ERR_NOT_DIR (1 << 0)
# define ERR_DENIED (1 << 2)
# define ERR_NOT_FOUND (1 << 3)

int			check_directory(char *path, char *base, char *filename);

void		builtin_echo(int argc, char **argv, t_var **envp);
void		builtin_env(int argc, char **argv, t_var **envp);
void		builtin_unsetenv(int argc, char **argv, t_var **envp);
void		builtin_cd(int argc, char **argv, t_var **envp);
void		builtin_setenv(int argc, char **argv, t_var **envp);

#endif
