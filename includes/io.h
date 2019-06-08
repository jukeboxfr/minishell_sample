#ifndef IO_H
# define IO_H

# include <unistd.h>
# include "libft.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define BUFF_SIZE 4096

int		read_until(char **line, char c, int keep);

#endif