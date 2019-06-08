/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_until.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 19:24:17 by kesaint-          #+#    #+#             */
/*   Updated: 2019/05/31 19:25:47 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"

static char		*update_line(char *dst, char *src)
{
	int		size;
	int		srclen;
	int		dstlen;
	char	*line;

	dstlen = dst ? ft_strlen(dst) : 0;
	srclen = ft_strlen(src);
	size = (dstlen + srclen) + 1;
	if (!(line = (char*)ft_memalloc(sizeof(char) * size)))
		return (NULL);
	if (dst)
	{
		ft_strcpy(line, dst);
		free(dst);
	}
	ft_strcpy(line + dstlen, src);
	return (line);
}

int				read_until(char **line, char c, int keep)
{
	char		buffer[BUFF_SIZE + 1];
	char		*src;
	char		*ptr;
	int			count;

	ft_memset(buffer, '\0', BUFF_SIZE);
	if (*buffer)
		count = ft_strlen(buffer);
	src = NULL;
	while (*buffer || (count = read(STDIN, buffer, BUFF_SIZE)) >= 0)
	{
		buffer[count] = '\0';
		if ((ptr = ft_strchr(buffer, c)))
			*(keep ? (ptr + 1) : ptr) = '\0';
		if (!(src = update_line(src, buffer)))
			return (-1);
		ptr ? ft_strcpy(buffer, ptr + 1) : ft_strncpy(buffer, "\0", 1);
		if (ptr || ((count < BUFF_SIZE) && src))
		{
			*line = src;
			return (ptr ? 1 : 0);
		}
	}
	return (count);
}
