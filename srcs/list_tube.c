/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tube.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 11:28:54 by jelefebv          #+#    #+#             */
/*   Updated: 2016/11/04 18:06:17 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "libft.h"

#include <stdio.h>

static int	ft_find_tubename_in_room(const char *str, const t_salle *room)
{
	while (room)
	{
		if (!ft_strcmp(room->name, str))
			return (0);
		room = room->next;
	}
	if (!room)
		return (0);
	return (1);
}

t_tube		*ft_new_tube(const char *str, const t_salle *room)
{
	char	**tmp;
	int		i;
	int		j;
	t_tube	*new;

	tmp = ft_strsplit(str, '-');
	if (!(new = (t_tube *)malloc(sizeof(t_tube))))
		return (NULL);
	new->enter = NULL;
	new->exit = NULL;
	i = 0;
	j = 0;
	while (tmp[i + 1] && ft_find_tubename_in_room(tmp[0], room))
		tmp[0] = ft_strjoin(tmp[0], ft_strjoin("-", tmp[i++]));
	j = ++i;
	while (ft_find_tubename_in_room(tmp[j++], room) && tmp[j])
		tmp[i] = ft_strjoin(tmp[i], ft_strjoin("-", tmp[j]));
	if (tmp[0] && tmp[i] && !tmp[j])
	{
		new->enter = ft_strdup(tmp[0]);
		new->exit = ft_strdup(tmp[i]);
		new->next = NULL;
	}
	ft_strstrdel(tmp);
	return (new);
}

int			ft_push_back_tube(t_tube **tube, const t_salle *room,
		const char *str)
{
	t_tube	*tmp;

	tmp = *tube;
	if (!tmp)
	{
		*tube = ft_new_tube(str, room);
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
		tmp->next = ft_new_tube(str, room);
		if (!(tmp->next) || !(tmp->next->enter) || !(tmp->next->exit))
		{
			tmp->next = NULL;
			return (-1);
		}
	}
	return (0);
}
