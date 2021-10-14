#include "../minishell.h"
#include <stdio.h>

void	test_execve(char *line)
{
	int		fork_id;
	char	*args1[] = {"-l", NULL};
	char	*args2[] = {"-l", "-a", NULL};
	char	*args3[] = {"-l", "-A", NULL};
	char	*args4[] = {"-la", NULL};
	char	*args5[] = {"-la", "/bin", NULL};
	char	*args6[] = {"", "/bin", NULL};
    char	*env[] = {"PATH=/bin", "USER=me", NULL};

	if (!ft_strcmp(line, "1"))
	{
		printf("here 1\n");
		// new process for command
		fork_id = fork();
		if (fork_id == 0) {
			if (execve("/bin/ls", args1, env) == -1)
			{
				// printf("failed\n");
				perror(NULL);
				// discard new process
				exit(EXIT_FAILURE);
			}
		}
	}
	if (!ft_strcmp(line, "2"))
	{
		printf("here 2\n");
		fork_id = fork();
		if (fork_id == 0) {
			if (execve("/bin/ls", args2, env) == -1)
			{
				// printf("failed\n");
				perror(NULL);
				exit(EXIT_FAILURE);
			}
		}
	}
	if (!ft_strcmp(line, "3"))
	{
		printf("here 3\n");
		fork_id = fork();
		if (fork_id == 0) {
			if (execve("/bin/ls", args3, env) == -1)
			{
				printf("failed\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	if (!ft_strcmp(line, "4"))
	{
		printf("here 4\n");
		fork_id = fork();
		if (fork_id == 0) {
			if (execve("/bin/ls", args4, env) == -1)
			{
				// printf("failed\n");
				perror(NULL);
				exit(EXIT_FAILURE);
			}
		}
	}
	if (!ft_strcmp(line, "5"))
	{
		printf("here 5\n");
		fork_id = fork();
		if (fork_id == 0)
		{
			if (execve("/bin/ls", args5, NULL) == -1)
			{
				// printf("failed\n");
				perror(NULL);
				exit(EXIT_FAILURE);
			}
		}
	}
	if (!ft_strcmp(line, "6"))
	{
		printf("here 5\n");
		fork_id = fork();
		if (fork_id == 0)
		{
			if (execve("/bin/ls", args6, NULL) == -1)
			{
				// printf("failed\n");
				perror(NULL);
				exit(EXIT_FAILURE);
			}
		}
	}

	// wait for child process to finish
	if (fork_id != 0)
		wait(NULL);
}

int	check_quotes(char *str)
{
	size_t	i;
	int		quote;

	// check not closed quote
	i = -1;
	quote = 0;
	while (str[++i])
	{
		if (str[i] == '\'' && quote == 0)
			quote = 1;
		else if (str[i] == '"' && quote == 0)
			quote = 2;
		else if (str[i] == '\'' == quote == 1)
			quote = 0;
		else if (str[i] == '"' && quote == 2)
			quote = 0;
	}
	return (quote);
}

char	*get_redirection(char *s, int *i)
{
	if (s[*i] == ';')
	{
		while (s[++(*i)] == ';')
		return (ft_substr(s, 0, *i));
	}
	if (s[*i] == '<')
	{
		while (s[++(*i)] == '<')
		return (ft_substr(s, 0, *i));
	}
	if (s[*i] == '>')
	{
		while (s[++(*i)] == '>')
		return (ft_substr(s, 0, *i));
	}
	if (s[*i] == '|')
	{
		while (s[++(*i)] == '|')
		return (ft_substr(s, 0, *i));
	}
}

// TODO :
	// new list n new cmd in while
void	handle_line(char *line)
{
	size_t		i;
	int		quote;
	size_t		start;
	size_t		end;
	t_cmd		cmd;
	t_lst_cmd	*cmd_head;
	t_lst_cmd	*commands;

	i = -1;
	quote = 0;
	start = 0;

	commands = ft_lstnew(&cmd);
	cmd_head = commands;

	while (line[++i])
	{
		if (line[i] == '\'' && quote == 0)
			quote = 1;
		else if (line[i] == '"' && quote == 0)
			quote = 2;
		else if (line[i] == '\'' == quote == 1)
			quote = 0;
		else if (line[i] == '"' && quote == 2)
			quote = 0;

		if (line[i] == ';' || line[i] == '>' || line[i] == '<' || line[i] == '|')
		{
			// store whats before
			if (i == 0)
				cmd.text = ft_strdup("");
			else
				cmd.text = ft_substr(line, start, i - start);
			// skip it
			cmd.redir_after = get_redirection(line, &i);
		}
	}
}
