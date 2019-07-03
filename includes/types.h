/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 13:04:01 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/08 13:09:44 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# define ERROR -1
# define SUCCESS 0

# define TRUE 1
# define FALSE 0

typedef int		t_bool;

typedef struct	s_var
{
	char			*name;
	char			*value;
	struct s_var	*previous;
	struct s_var	*next;
}				t_var;

typedef struct	s_command
{
	int					argc;
	char				**argv;
	t_var				*env;
	struct s_command	*next;
}				t_command;

#endif
