/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 16:25:12 by jelefebv          #+#    #+#             */
/*   Updated: 2016/11/04 12:21:04 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "ft_printf.h"

void	ft_print_lemin(t_lem *l)
{
	ft_printf("fourmis nb :%d\n##start\n%s %d %d\n##end\n%s %d %d\ncommand :\n",
	l->nb_fourmis, l->start, l->startx, l->starty, l->end, l->endx, l->endy);
	while (l->command)
	{
		ft_printf("##%s\n", l->command->command);
		l->command = l->command->next;
	}
	ft_printf("comment :\n");
	while (l->comment)
	{
		ft_printf("#%s\n", l->comment->comment);
		l->comment = l->comment->next;
	}
	ft_printf("room :\n");
	while (l->map)
	{
		ft_printf("%s %d %d\n", l->map->name, l->map->x, l->map->y);
		l->map = l->map->next;
	}
	ft_printf("tube :\n");
	while (l->tube)
	{
		ft_printf("%s-%s\n", l->tube->enter, l->tube->exit);
		l->tube = l->tube->next;
	}
}
