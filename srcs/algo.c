/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:27:11 by jelefebv          #+#    #+#             */
/*   Updated: 2016/11/07 10:23:51 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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
