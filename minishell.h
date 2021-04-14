#ifndef MINISHELL_H

# define MINISHELL_H

# include "libft/libft.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include <dirent.h>

int		get_next_line(int fd, char **line);

#endif
