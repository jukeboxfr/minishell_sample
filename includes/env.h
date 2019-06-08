/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 12:30:15 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/08 13:53:11 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "libft.h"
# include "types.h"

char			**str_env(t_var *env);
t_var			*parse_envp(char **envp);

char 			*get_var(t_var *env, char *name);
void			edit_var(t_var *env, char *name, char *value);
void			append_var(t_var **envp, t_var *var);
void			remove_var(t_var **envp, char *name);

void			clear_var(t_var *var);
void			clear_envp(t_var **envp);

#endif
