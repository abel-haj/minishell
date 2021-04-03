/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-haj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 05:07:14 by abel-haj          #+#    #+#             */
/*   Updated: 2021/03/31 19:48:00 by abel-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	free_and_return(char *fs, char *ss, int ret)
{
	free(fs);
	free(ss);
	fs = NULL;
	ss = NULL;
	return (ret);
}

static void	joinnfree(char **line, char **buff)
{
	char	*tmp;

	tmp = *line;
	*line = ft_strjoin(*line, *buff);
	free(tmp);
}

static int	ft_stcnl(char **ln, char **b, int n, char **lft)
{
	char	*tmp;

	(*lft)[n] = '\0';
	tmp = *ln;
	if ((*ln = ft_strjoin(*ln, *lft)) == NULL)
		return (free_and_return(*b, NULL, -1));
	free(tmp);
	tmp = *lft;
	if ((*lft = ft_strdup(*lft + n + 1)) == NULL)
		return (free_and_return(*b, NULL, -1));
	return (free_and_return(*b, tmp, 1));
}

static int	ft_nl(char **ln, char **b, int n, char **lft)
{
	char	*tmp;

	(*b)[n] = '\0';
	tmp = *ln;
	if ((*ln = ft_strjoin(*ln, *b)) == NULL)
		return (free_and_return(*b, NULL, -1));
	if ((*lft = ft_strdup(*b + n + 1)) == NULL)
		return (free_and_return(*b, NULL, -1));
	free_and_return(*b, tmp, 0);
	return (1);
}

int			get_next_line(int fd, char **line)
{
	int			i;
	long int	nlp;
	char		*buff;
	static char	*left[1024] = {NULL};

	if (fd < 0 || !line || !(*line = ft_strdup("")) ||
	!(buff = malloc(100 + 1)) || read(fd, NULL, 0) < 0)
		return (-1);
	if (left[fd] != NULL)
	{
		if ((nlp = ft_strindof(left[fd], '\n')) > -1)
			return (ft_stcnl(line, &buff, nlp, &left[fd]));
		joinnfree(line, &left[fd]);
		free(left[fd]);
		left[fd] = 0;
	}
	while ((i = read(fd, buff, 100)) > 0)
	{
		buff[i] = 0;
		if ((nlp = ft_strindof(buff, '\n')) > -1)
			return (ft_nl(line, &buff, nlp, &left[fd]));
		joinnfree(line, &buff);
	}
	return (free_and_return(buff, NULL, i));
}
