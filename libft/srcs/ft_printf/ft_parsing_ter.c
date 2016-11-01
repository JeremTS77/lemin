/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_ter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 14:57:13 by jelefebv          #+#    #+#             */
/*   Updated: 2015/02/13 14:58:09 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_glhf(t_flag *list, int nb)
{
	int		i;

	i = list->nbchar - nb;
	(void)list;
	(void)nb;
	while (list->nbchar > nb)
	{
		list->string = ft_keepstring_inv(' ', list->string);
		nb++;
	}
	return (i);
}

int		ft_glhfmin(t_flag *list, int nb)
{
	int		i;

	i = list->nbchar - nb;
	while (list->nbchar > nb)
	{
		list->string = ft_keepstring(' ', list->string);
		nb++;
	}
	return (i);
}
