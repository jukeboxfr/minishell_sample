/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 11:58:49 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/08 13:06:57 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H

# include "libft.h"
# include "types.h"

void			clear_command(t_command **command_p);
t_command		*parse_command(char *str);

#endif
