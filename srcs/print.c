/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 16:25:12 by jelefebv          #+#    #+#             */
/*   Updated: 2016/12/09 12:28:00 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "ft_printf.h"

void	ft_print_lemin(t_lem l)
{
	ft_printf("%d\n##start\n%s %d %d\n##end\n%s %d %d\n",
	l.nb_fourmis, l.start, l.startx, l.starty, l.end, l.endx, l.endy);
	while (l.map)
	{
		if (ft_strcmp(l.map->name, l.start) && ft_strcmp(l.map->name, l.end))
			ft_printf("%s %d %d\n", l.map->name, l.map->x, l.map->y);
		l.map = l.map->next;
	}
	while (l.tube)
	{
		ft_printf("%s-%s\n", l.tube->enter, l.tube->exit);
		l.tube = l.tube->next;
	}
	ft_printf("\n");
}
