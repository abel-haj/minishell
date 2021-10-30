#include "../minishell.h"

static size_t	count_splitted_wq(char *s)
{
	size_t	i;
	int		quote;

	i = -1;
	quote = 0;
	while (s[++i])
	{
		if (s[i] == '\'' && quote == 0)
			quote = 1;
		else if (s[i] == '"' && quote == 0)
			quote = 2;
		else if (s[i] == '\'' == quote == 1)
			quote = 0;
		else if (s[i] == '"' && quote == 2)
			quote = 0;

		if (s[i] == '|' && quote == 0)
			quote++;
	}
	return (quote);
}

**	ft_split_wq(char *s, char c)
{
	size_t	start;
	size_t	end;
	size_t	i;
	size_t	len;
	char	**result;

	i = 0;
	start = i;
	end = start;
	len	= count_splitted_wq(s);
	result = malloc(sizeof(char *) * len + 1);
	if (!result)
		return (NULL);

	while (result[++i])
	{
		//
	}

	result[len - 1] = NULL;
	return (result);
}