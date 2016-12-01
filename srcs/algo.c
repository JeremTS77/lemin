/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:24:47 by jelefebv          #+#    #+#             */
/*   Updated: 2016/12/01 23:23:38 by jeremy           ###   ########.fr       */
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
	while (tmp_t)
	{
		if (ft_get_salle(lem->map, name) && !ft_strcmp(tmp_t->enter, name)
				&& ft_get_salle(lem->map, name)->weight > index)
		{
			tmp_s = ft_get_salle(lem->map, name);
			tmp_s->weight = (index < tmp_s->weight) ? index : tmp_s->weight;
			ft_rec(lem, tmp_t->exit, index + 1);
			return ;
		}
		else if (ft_get_salle(lem->map, name) && !ft_strcmp(tmp_t->exit, name)
				&& ft_get_salle(lem->map, name)->weight > index)
		{
			tmp_s = ft_get_salle(lem->map, name);
			tmp_s->weight = (index < tmp_s->weight) ? index : tmp_s->weight;
			ft_rec(lem, tmp_t->enter, index + 1);
			return ;
		}
		tmp_t = tmp_t->next;
	}
}
