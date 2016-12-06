/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeremy <jeremy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 17:10:34 by jeremy            #+#    #+#             */
/*   Updated: 2016/12/05 12:07:35 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lemin.h"

t_salle		*ft_new_salle(const char *str)
{
	t_salle		*new;
	char		**tmp;

	tmp = ft_strsplit(str, ' ');
	if (!(new = (t_salle *)malloc(sizeof(t_salle))))
		return (NULL);
	new->name = NULL;
	if (tmp[0] && tmp[1] && tmp[2] && !tmp[3] && tmp[0][0] != 'L')
	{
		new->name = ft_strtrim(tmp[0]);
		new->x = ft_atoi(tmp[1]);
		new->y = ft_atoi(tmp[2]);
		new->weight = 0;
		new->next = NULL;
	}
	ft_strstrdel(tmp);
	return (new);
}

int			ft_push_back_salle(t_salle **salle, const char *str)
{
	t_salle		*tmp;

	tmp = *salle;
	if (!tmp)
	{
		*salle = ft_new_salle(str);
		if (!*salle || !(*salle)->name)
		{
			*salle = NULL;
			return (-1);
		}
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_new_salle(str);
		if (!(tmp->next) || !tmp->next->name)
		{
			tmp->next = NULL;
			return (-1);
		}
	}
	return (0);
}
