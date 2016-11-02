/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 16:25:12 by jelefebv          #+#    #+#             */
/*   Updated: 2016/11/02 18:03:16 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "ft_printf.h"

void	ft_print_lemin(t_lem *lem)
{
	ft_printf("%d\n##start\n%s %d %d\n##end\n%s %d %d\n", lem->nb_fourmis,
			lem->start, lem->startx, lem->starty, lem->end, lem->endx,
			lem->endy);
}
