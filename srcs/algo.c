/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:24:47 by jelefebv          #+#    #+#             */
/*   Updated: 2016/12/05 12:52:35 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		ft_count_room(t_salle *room, int *c)
{
	t_salle		*tmp;
	int			i;

	tmp = room;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		++i;
	}
	tmp = room;
	while (tmp)
	{
		tmp->weight = i + 1;
		tmp = tmp->next;
	}
	*c = i;
}

t_salle		*ft_get_salle(t_salle *room, char *name)
{
	while (room)
	{
		if (!ft_strcmp(name, room->name))
			return (room);
		room = room->next;
	}
	return (NULL);
}

void		ft_rec(t_lem *lem, char *name, int index)
{
	t_salle		*tmp_s;
	t_tube		*tmp_t;

	tmp_t = lem->tube;
	if ((tmp_s = ft_get_salle(lem->map, name)) != NULL)
		tmp_s->weight = (index < tmp_s->weight) ? index : tmp_s->weight;
	while (tmp_t)
	{
		if (ft_get_salle(lem->map, tmp_t->exit)
				&& !ft_strcmp(tmp_t->enter, name)
				&& ft_get_salle(lem->map, tmp_t->exit)->weight > index)
		{
			ft_rec(lem, tmp_t->exit, index + 1);
		}
		else if (ft_get_salle(lem->map, tmp_t->enter)
				&& !ft_strcmp(tmp_t->exit, name)
				&& ft_get_salle(lem->map, tmp_t->enter)->weight > index)
		{
			ft_rec(lem, tmp_t->enter, index + 1);
		}
		tmp_t = tmp_t->next;
	}
}
