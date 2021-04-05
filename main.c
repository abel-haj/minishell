#include "minishell.h"

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

// void		ft_treat_line(char *line)
// {
// 	char	**cmds;

// 	// split commands
// 	cmds = ft_split(line, ';');
// 	// split pipes
// 	printf("\n%d\n", ft_countsplit(line, c));
// }

int			main(int argc, char *argv[])
{
	char	*line;
	char	*exargs[] = {"/", NULL};
	// char	**exargs;
	// **exargs = {"/", NULL};

	execve("/bin/ls", exargs, NULL);
	// while (get_next_line(0, &line) >= 0)
	// {
	// 	// printf("%s\n", line);
	// 	ft_treat_line(line);
	// 	free(line);
	// }
	return (0);
}
