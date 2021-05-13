#include "minishell.h"

void		ft_putsentence(char *s1, char *s2, char *s3)
{
	if (s1)
		ft_putstr(s1);
	if (s2)
		ft_putstr(s2);
	if (s3)
		ft_putstr(s3);
}

size_t		ft_countsplit(const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			i++;
		if (s[i - 1] != c)
			j++;
	}
	return (j);
}

int			ft_isdir(char *dirpath)
{
	DIR		*dir = opendir(dirpath);
	if (dir) {
		closedir(dir);
		return (1);
	} else {
		return (0);
	}
}

int		ft_strcmp( char *s1,  char *s2)
{
	size_t			i;
	unsigned char	*f_string;
	unsigned char	*s_string;

	i = 0;
	f_string = (unsigned char *)s1;
	s_string = (unsigned char *)s2;
	while (f_string[i] || s_string[i])
	{
		if (f_string[i] != s_string[i])
			return (f_string[i] - s_string[i]);
		else if (f_string[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

size_t		ft_strrindof(char *s, char c)
{
	size_t	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == c)
			return (i);
		i--;
	}
	return (i);
}

char		*ft_cleanstr(char *str)
{
	char	*new_s;
	int		w_quote;
	int		s_quote;
	int		d_quote;
	size_t	i;

	new_s = NULL;
	w_quote = 0;
	s_quote = 0;
	d_quote = 0;
	i = 0;

/*
''""
	0 = none
	' = 1
	" = 2
*/
	while (str[i])
	{
		if (str[i] == )
		i++;
	}
}

void		ft_which_command(char *cmd)
{
	char	**options;
	size_t	c;
	size_t	i;
	size_t	indx;
	int		fd;

	options = ft_split(cmd, ' ');
	c = ft_countsplit(cmd, ' ');

	if (ft_strcmp(options[0], "cd") == 0)
	{
		// variables

		// check only first path
		// if none, do nothing
		if (c >= 2)
		{
			fd = open(options[1], O_RDONLY);
			if (fd == -1)
				// printf("cd: %s: No such file or directory\n", options[1]);
				ft_putsentence("cd: ", options[1], ": No such file or directory\n");
			else
			{
				close(fd);
				if (ft_isdir(options[1]))
				{
					options[1] = ft_cleanstr(options[1]);
					chdir(options[1]);
				}
				else
				{
					// printf("cd: %s: Not a directory\n", options[1]);
					ft_putsentence("cd: ", options[1], ": Not a directory\n");
				}
			}
			// struct stat b;
			// stat(options[1], &b);
		}
	}

	else if (ft_strcmp(options[0], "echo") == 0)
	{
		// single quotes
		// double quotes
		// variables

		// get printable part of line
		// remove parent quotes
		if (c >= 2)
		{
			// -n
			if (ft_strcmp(options[1], "-n") == 0)
			{
				i = 2;
				while (i < c)
				{
					if (i > 2)
						ft_putchar(' ');
					// printf("%s", options[i]);
					ft_putstr(options[i]);
					i++;
				}
			}

			else
			{
				i = 1;
				while (i < c)
				{
					if (i > 1)
						ft_putchar(' ');
					// printf("%s", options[i]);
					ft_putstr(options[i]);
					i++;
				}
				ft_putchar('\n');
			}
		}
	}

	else if (ft_strcmp(options[0], "env") == 0)
	{}

	else if (ft_strcmp(options[0], "exit") == 0)
	{
		// free n quit
		exit(0);
	}

	else if (ft_strcmp(options[0], "export") == 0)
	{}

	else if (ft_strcmp(options[0], "pwd") == 0)
	{
		// printf("%s\n", getcwd(NULL, 0));
		ft_putsentence(getcwd(NULL, 0), "\n", NULL);
	}

	else if (ft_strcmp(options[0], "unset") == 0)
	{}

	else
	{
		// printf("%s: command was not found\n", options[0]);
		ft_putsentence(options[0], ": command was not found\n", NULL);
	}
}

void		ft_treat_line(char *line)
{
	char	**cmds;
	size_t	c;
	size_t	i;

	// split commands
	cmds = ft_split(line, ';');
	c = ft_countsplit(line, ';');

	if (c >= 1)
	{
		// 1 command
		// could contain '>' or '|'

		i = 0;
		while (i < c)
		{
			ft_which_command(cmds[i]);
			i++;
		}
	}
	else if (ft_strlen(line) >= 1)
	{
		// Ex: ";"
		// printf("syntax error\n");
		ft_putstr("syntax error\n");
	}
	// printf("\n%zu\n", c);

	// split pipes
}

int			main(int argc, char *argv[])
{
	char	*line;
	// char	**exargs;
	// **exargs = {"/", NULL};

	// char	*exargs[] = {"/", NULL};

	// execve("/bin/ls", exargs, NULL);

	while (write(1, "$ ", 2) && get_next_line(0, &line) >= 0)
	{
		// printf("%s\n", line);
		ft_treat_line(line);
		free(line);
	}
	return (0);
}
