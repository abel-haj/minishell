/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houbeid <houbeid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:08:05 by houbeid           #+#    #+#             */
/*   Updated: 2021/12/09 03:32:49 by houbeid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	typered_norm(int redir, char *filename, int ambig)
{
	int	fd;

	fd = macro_red(redir, filename, ambig);
	if (fd == 0)
		return (0);
	if (fd < 0)
		return (fd);
	return (fd);
}

void	macro_init_options(t_imp *tmp, int i, int j)
{
	char	*opt;
	int		len;

	len = 0;
	while (g_global->lst->options[i][j] == '=')
		j++;
	opt = ft_strchr((g_global->lst->options[i] + j), '=');
	if (opt)
	{
		len = opt - g_global->lst->options[i];
		tmp->key = ft_substr_wrap(g_global->lst->options[i], 0, len);
		if (opt[1] == '"' || opt[1] == '\'')
			tmp->value = ft_substr_wrap(g_global->lst->options[i],
					len + 1 + 1, ft_strlen(opt) - 1 - 2);
		else
			tmp->value = ft_substr_wrap(g_global->lst->options[i],
					len + 1, ft_strlen(g_global->lst->options[i]));
		tmp->egale = 1;
	}
	else
	{
		tmp->key = ft_strdup_wrap(g_global->lst->options[i]);
		tmp->value = NULL;
		tmp->egale = 0;
	}
}

t_imp	*init_options(void)
{
	t_imp	*init;
	t_imp	*tmp;
	int		i;

	i = 1;
	init = pmalloc(sizeof(t_imp));
	tmp = init;
	while (g_global->lst->options[i])
	{
		macro_init_options(tmp, i, 0);
		if (!g_global->lst->options[i + 1])
			break ;
		tmp->next = pmalloc(sizeof(t_imp));
		tmp = tmp->next;
		i++;
	}
	tmp->next = NULL;
	return (init);
}

void	execute(t_imp **imp)
{
	int	i;

	if (!ft_strcmp(g_global->error, "0"))
	{
		if (g_global->lst->mini_cmd != NULL)
			i = redirection(imp);
		else if (g_global->lst->cmd)
		{
			if (g_global->lst->is_builtin == 1)
				is_builtin(imp);
			else
				ft_execve(imp);
		}
	}
}
