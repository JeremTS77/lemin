/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 16:25:33 by jelefebv          #+#    #+#             */
/*   Updated: 2016/12/06 18:55:08 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "ft_printf.h"

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
	int		weight;
	int		*f;

	i = 0;
	if (!(f = (int *)malloc(sizeof(int) * nb + 1)))
		return ;
	while (i != nb)
		f[i++] = 0;
	weight = 0;
	while (f[nb - 1] != end)
	{
		i = 0;
		while (i < nb)
		{
			if (f[i] == 0 && f[i] != end)
			{
				f[i] += 1;
				ft_printf("L%d-%s ", i + 1, ft_get_salle_weight(lst, f[i]));
				break ;
			}
			if (f[i] != end)
			{
				f[i] += 1;
				ft_printf("L%d-%s ", i + 1, ft_get_salle_weight(lst, f[i]));
			}
			++i;
		}
		if (i == nb)
			++weight;
		ft_printf("\n");
	}
}
