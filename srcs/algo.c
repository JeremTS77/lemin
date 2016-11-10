/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:27:11 by jelefebv          #+#    #+#             */
/*   Updated: 2016/11/10 18:28:55 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
   t_tube	*ft_find_tube(const char *name, t_tube *tube)
   {
   while (tube)
   {
   if (!ft_strcmp(tube->enter == name))
   return (tube);
   tube = tube->next;
   }
   return (NULL);
   }

   t_tube	*ft_find_path(const t_tube *begin_tube, t_tube *tube, const char *start,
   const char *end)
   {
   t_tube	*new;

   if (!(tube = ft_find_tube(start, begin_tube)))
   return (NULL);
   if (!(new = ft_find_path(begin_tube, tube, tube->exit, end)))
   return (NULL);
   }
   */

int		ft_compte_room(t_salle *room)
{
	int		i;

	i = 0;
	while (room)
	{
		room = room->next;
		++i;
	}
	return (i);
}

void	ft_mark_room(char *end, t_tube *begin, t_salle *room, int weight)
{
	t_tube		*tube;
	t_salle		*lst_room;

	if (end && *end && begin && room && weight >= 0)
	{
		tube = begin;
		lst_room = room;
		while (tube)
		{
			lst_room = room;
			while (tube && ft_strcmp(tube->exit, end))
				tube = tube->next;
			while (lst_room && ft_strcmp(lst_room->name, end))
				lst_room = lst_room->next;
			if (tube && lst_room && tube->next)
			{
				lst_room->weight = weight;
				ft_mark_room(tube->exit, begin, room, weight - 1);
			}
		}
	}
}

void	ft_mark(const char *end, const char *enter, t_tube *begin, t_salle **room, int weight)
{
	t_tube		*tube;
	t_salle		*salle;
	char		*current;

	tube = begin;
	salle = *room;
	current = ft_strdup(end);
	while (ft_strcmp(current, enter))
	{
		salle = *room;
		while (salle && ft_strcmp(current, salle->name))
			salle = salle->next;
		salle->weight = weight;
		while (tube)
		{
			if (!ft_strcmp(current, tube->exit))
			{
				salle = *room;
				while (salle && ft_strcmp(tube->enter, salle->name))
					salle = salle->next;
				salle->weight = weight - 1;
			}
			tube = tube->next;
		}
	}
	ft_strdel(&current);
}
