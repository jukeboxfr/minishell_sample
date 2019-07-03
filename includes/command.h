/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 11:58:49 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/08 18:08:21 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include <pwd.h>
# include <sys/types.h>
# include <unistd.h>

# include "libft.h"
# include "types.h"
# include "env.h"

void			replace_vars(t_var *env, char **argv);

t_command		*parse_command(t_var *env, char *str);

#endif
