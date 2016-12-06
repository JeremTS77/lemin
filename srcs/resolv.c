/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:56:58 by jelefebv          #+#    #+#             */
/*   Updated: 2016/12/06 18:13:04 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"
#include "libft.h"

void			ft_putendl_fd_exit(const char *error, int fd)
{
	ft_putendl_fd(error, fd);
	exit(0);
}

void			ft_check_error(t_lem *lem, int *c)
{
	int			i;
	int			j;
	t_salle		*room;

	i = 0;
	j = 0;
	room = lem->map;
	if (lem->nb_fourmis <= 0 || !lem->start || !*lem->start)
		ft_putendl_fd_exit("ERROR", 2);
	if (!lem->end || !*lem->end || !lem->map || !lem->tube)
		ft_putendl_fd_exit("ERROR", 2);
	if (ft_get_salle(lem->map, lem->end)->weight >= *c)
		ft_putendl_fd_exit("ERROR", 2);
}

static void		push_back_room(t_salle **room, t_salle *salle)
{
	t_salle		*tmp;

	tmp = *room;
	if (!tmp || !tmp->name)
	{
		*room = salle;
		(*room)->next = NULL;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		salle->next = NULL;
		tmp->next = salle;
	}
}

t_salle			*ft_get_lst_resolv(t_lem *lem)
{
	t_salle		*tmp_s;
	t_salle		*lst;
	int			index;

	tmp_s = lem->map;
	index = 0;
	lst = NULL;
	while (tmp_s)
	{
		if (tmp_s->weight == index)
		{
			push_back_room(&lst, tmp_s);
			tmp_s = lem->map;
			++index;
		}
		tmp_s = tmp_s->next;
	}
	tmp_s = lst;
	while (tmp_s->next)
		tmp_s = tmp_s->next;
	if (!lst || !lst->name)
		ft_putendl_fd_exit("ERROR", 2);
	return (lst);
}
