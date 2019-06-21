/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 12:16:45 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/10 19:25:14 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "command.h"
# include "io.h"
# include "types.h"

void		builtin_echo(int argc, char **argv, t_var **envp);
void		builtin_env(int argc, char **argv, t_var **envp);
void		builtin_unsetenv(int argc, char **argv, t_var **envp);
void		builtin_cd(int argc, char **argv, t_var **envp);
void		builtin_setenv(int argc, char **argv, t_var **envp);

#endif
