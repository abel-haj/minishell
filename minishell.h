#ifndef MINISHELL_H

# define MINISHELL_H

# include "libft/libft.h"
// malloc, ...
# include <stdlib.h>
// write, execve, ...
# include <unistd.h>
// open, ...
# include <fcntl.h>
// wait
# include <sys/wait.h>
// readline, add_history
# include <readline/readline.h>
# include <readline/history.h>

# include <dirent.h>

// [*1, *2, *3, NULL]
// 0 OR 1
typedef struct s_cmd {
	char		*cmd;
	char		**options;
	char		**arguments;
	char		is_builtin;
}				t_cmd;

int		get_next_line(int fd, char **line);

#endif
