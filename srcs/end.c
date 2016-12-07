/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 16:25:33 by jelefebv          #+#    #+#             */
/*   Updated: 2016/12/07 18:11:28 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "ft_printf.h"

void	ft_push_back(t_salle **new, t_salle *tmp)
{
	t_salle		*begin;
	t_salle		*yolo;

	begin = *new;
	if (!(yolo = (t_salle *)malloc(sizeof(t_salle))))
		return ;
	if (tmp && tmp->name)
	{
		yolo->name = ft_strdup(tmp->name);
		yolo->x = tmp->x;
		yolo->y = tmp->y;
		yolo->weight = tmp->weight;
		yolo->next = NULL;
	}
	if (!new || !*new)
		*new = yolo;
	else
	{
		while (begin->next)
			begin = begin->next;
		begin->next = yolo;
	}
}

void	ft_sort(t_salle **lst, int nb)
{
	t_salle		*tmp;
	t_salle		*new;
	int			i;

	i = 0;
	tmp = *lst;
	new = NULL;
	while (i < nb)
	{
		while (tmp)
		{
			if (tmp->weight == i)
				ft_push_back(&new, tmp);
			tmp = tmp->next;
		}
		tmp = *lst;
		++i;
	}
	*lst = new;
}

char	*ft_get_salle_weight(t_salle *lst, int weight)
{
	t_salle		*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->weight == weight)
			return (tmp->name);
		tmp = tmp->next;
	}
	return (NULL);
}

void	ft_print_resolve(t_salle *lst, int nb, int end)
{
	int		i;
	int		*f;

	i = 0;
	if (!(f = (int *)malloc(sizeof(int) * nb + 1)))
		return ;
	while (i != nb)
		f[i++] = 0;
	while (f[nb - 1] != end)
	{
		i = 0;
		while (i < nb)
		{
			if (f[i] != end)
			{
				f[i] += 1;
				ft_printf("L%d-%s ", i + 1, ft_get_salle_weight(lst, f[i]));
				if (f[i] == 1)
					break ;
			}
			++i;
		}
		ft_printf("\n");
	}
}
