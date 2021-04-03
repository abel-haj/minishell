/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-haj <abel-haj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 06:50:13 by abel-haj          #+#    #+#             */
/*   Updated: 2021/04/03 18:47:20 by abel-haj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;
	t_list *l;

	if (lst && del)
	{
		l = *lst;
		while (l)
		{
			tmp = l;
			l = l->next;
			del(tmp->content);
			free(tmp);
		}
		*lst = NULL;
	}
}

void		ft_d(void *data)
{
	if (data)
		data = NULL;
}
