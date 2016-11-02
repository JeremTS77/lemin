/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeremy <jeremy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 17:10:34 by jeremy            #+#    #+#             */
/*   Updated: 2016/11/02 11:42:01 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "lemin.h"

t_salle		*ft_new_salle(const char *str)
{
	t_salle		*new;
	char		**tmp;

	tmp = ft_strsplit(str, ' ');
	if (!(new = (t_salle *)malloc(sizeof(t_salle))))
		return (NULL);
	new->name = NULL;
	if (tmp[0] && tmp[1] && tmp[2] && !tmp[3])
	{
		new->name = ft_strdup(tmp[0]);
		new->x = ft_atoi(tmp[1]);
		new->y = ft_atoi(tmp[2]);
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

void		ft_print_salle(t_salle *salle)
{
	if (salle)
	{
		while (salle)
		{
			ft_printf("name : %s, x : %d, y %d\n", salle->name, salle->x, salle->y);
			salle = salle->next;
		}
	}
}
