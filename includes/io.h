#ifndef IO_H
# define IO_H


# include <stdio.h>
# include <sys/stat.h>
# include <unistd.h>
# include <sys/types.h>
# include <dirent.h>
# include <unistd.h>

# include "libft.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define BUFF_SIZE 4096

# define MAX_PATH 255

typedef DIR*			t_dir;
typedef struct dirent	t_dirent;
typedef int				t_bool;

int		read_until(char **line, char c, int keep);

#endif