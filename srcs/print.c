/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 16:25:12 by jelefebv          #+#    #+#             */
/*   Updated: 2016/11/02 21:24:10 by jeremy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "ft_printf.h"

void	ft_print_lemin(t_lem *lem)
{
	ft_printf("\n\nprint with print_lemin : \n\n");
	ft_printf("%d\n##start\n%s %d %d\n##end\n%s %d %d\ncommand :\n", lem->nb_fourmis,
			lem->start, lem->startx, lem->starty, lem->end, lem->endx,
			lem->endy);
	while (lem->command)
	{
		ft_printf("##%s\n", lem->command->command);
		lem->command = lem->command->next;
	}
	ft_printf("comment :\n");
	while (lem->comment)
	{
		ft_printf("##%s\n", lem->comment->comment);
		lem->comment = lem->comment->next;
	}
	ft_printf("room :\n");
	while (lem->map)
	{
		ft_printf("name : %s, x : %d, y %d\n", lem->map->name, lem->map->x, lem->map->y);
		lem->map = lem->map->next;
	}
	ft_printf("tube :\n");
	while (lem->tube)
	{
		ft_printf("enter : %s, exit : %s\n", lem->tube->enter, lem->tube->exit);
		lem->tube = lem->tube->next;
	}
}
