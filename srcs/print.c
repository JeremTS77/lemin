/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 16:25:12 by jelefebv          #+#    #+#             */
/*   Updated: 2016/11/03 18:16:52 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "ft_printf.h"

void	ft_print_lemin(t_lem *lem)
{
	ft_printf("fourmis nb :%d\n", lem->nb_fourmis);
	ft_printf("##start\n%s %d %d\n", lem->start, lem->startx, lem->starty);
	ft_printf("##end\n%s %d %d\n", lem->end, lem->endx, lem->endy);
	ft_printf("command :\n");
	while (lem->command)
	{
		ft_printf("##%s\n", lem->command->command);
		lem->command = lem->command->next;
	}
	ft_printf("comment :\n");
	while (lem->comment)
	{
		ft_printf("#%s\n", lem->comment->comment);
		lem->comment = lem->comment->next;
	}
	ft_printf("room :\n");
	while (lem->map)
	{
		ft_printf("%s %d %d\n", lem->map->name, lem->map->x, lem->map->y);
		lem->map = lem->map->next;
	}
	ft_printf("tube :\n");
	while (lem->tube)
	{
		ft_printf("%s-%s\n", lem->tube->enter, lem->tube->exit);
		lem->tube = lem->tube->next;
	}
}
