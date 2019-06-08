/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 14:58:25 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/08 15:00:21 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"
# include "types.h"

char		*resolve_path(char *str);
char		*join_path(char *path, char *filename);
char		*get_base_path(char *str);
char		*get_filename(char *str);

#endif
