/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 11:28:54 by jelefebv          #+#    #+#             */
/*   Updated: 2016/11/03 17:14:26 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

t_tube	*ft_new_tube(const char *str)
{
	t_tube	*new;
	char	**tmp;

	tmp = ft_strsplit(str, '-');
	if (!(new = (t_tube *)malloc(sizeof(t_tube))))
		return (NULL);
	new->enter = NULL;
	new->exit = NULL;
	if (tmp[0] && tmp[1] && !tmp[2])
	{
		new->enter = ft_strdup(tmp[0]);
		new->exit = ft_strdup(tmp[1]);
		new->next = NULL;
	}
	ft_strstrdel(tmp);
	return (new);
}

int		ft_push_back_tube(t_tube **tube, const char *str)
{
	t_tube	*tmp;

	tmp = *tube;
	if (!tmp)
	{
		*tube = ft_new_tube(str);
		if (!*tube || !(*tube)->enter || !(*tube)->exit)
		{
			*tube = NULL;
			return (-1);
		}
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_new_tube(str);
		if (!(tmp->next) || !(tmp->next->enter) || !(tmp->next->exit))
		{
			tmp->next = NULL;
			return (-1);
		}
	}
	return (0);
}
