#include "minishell.h"
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

int	main(void)
{
	char	*line;

	while (1)
	{
		line = readline("minishell% ");

		// if line is not empty
		// add it to history
		if (*line) {
			add_history(line);
			test_execve(line);
		}

		if (!ft_strncmp(line, "exit", 4))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		free(line);
	}
	return (0);
}