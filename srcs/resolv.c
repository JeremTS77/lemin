/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:56:58 by jelefebv          #+#    #+#             */
/*   Updated: 2016/12/01 23:27:34 by jeremy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lemin.h"
#include "libft.h"

static void ft_putendl_fd_exit(const char *error, int fd)
{
	ft_putendl_fd(error, fd);
	exit(0);
}

void	ft_check_error(t_lem *lem, int *c)
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
//	while (i <= j)
//	{
//		while (room)
//		{
//			if (room->weight == i)
//			{
//				room = lem->map;
//				++i;
//			}
//			room = room->next;
//		}
//		if (i == j)
//			ft_putendl_fd_exit("ERROR", 2);
//	}
}
