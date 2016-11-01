/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 14:56:05 by jelefebv          #+#    #+#             */
/*   Updated: 2016/03/22 11:31:01 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int		ft_parsing(t_flag *list)
{
	int		nb;
	int		isneg;

	isneg = 0;
	nb = ft_strlen(list->string);
	if (list->c == 'd' || list->c == 'i')
		list->string = ft_parsmoins(&isneg, list->string);
	nb = ft_opt_all(nb, isneg, list, *(list->format));
	if (list->cnull == 1)
		return (nb + 1);
	return (nb);
}

int		ft_opt_point_nbr(int nb, t_flag *list, int isneg)
{
	isneg == 1 ? nb-- : nb;
	while (list->nbpoint > nb)
	{
		list->string = ft_keepstring_inv('0', list->string);
		nb++;
	}
	nb = ft_strlen(list->string);
	isneg == 1 ? nb++ : nb;
	return (nb);
}

int		ft_opt_point_adr(int nb, t_flag *list)
{
	char	*tmp;

	tmp = malloc(sizeof(nb));
	tmp = ft_strncpy(tmp, list->string, 2);
	nb = nb - 3;
	while (list->nbpoint > nb)
	{
		tmp = ft_keepstring('0', tmp);
		list->string++;
		nb++;
	}
	tmp = ft_strjoin(tmp, list->string);
	ft_strcpy(list->string, tmp);
	nb = ft_strlen(list->string);
	list->string = tmp;
	return (nb);
}

int		ft_opt_point_null(t_flag *list, char c)
{
	int		i;

	i = 0;
	if (c == 's' && list->zero == 1)
	{
		while (list->nbchar > i++)
			list->string = ft_keepstring_inv('0', list->string);
		return (--i);
	}
	else
		return (ft_opt_point_null_bis(list, c, i));
}

int		ft_opt_point_null_bis(t_flag *list, char c, int i)
{
	if (c == 'p')
	{
		list->string = ft_delstr();
		list->string = ft_strjoin("0x", list->string);
		return (2);
	}
	else if (list->hash == 1 && (c == 'o' || c == 'O'))
	{
		if (list->null == 0)
			list->string = ft_keepstring_inv('0', list->string);
		return (ft_strlen(list->string));
	}
	else if (c != 's' && c != 'S' && c != 'p' && c != 'd' && c != 'D'
		&& c != 'o' && c != 'o' && c != 'O' && c != 'u' && c != 'U'
		&& c != 'x' && c != 'X' && c != 'i')
	{
		while (list->nbchar - 1 > i++)
			list->string = ft_keepstring_inv('0', list->string);
		return (i);
	}
	else
	{
		list->string = ft_delstr();
		return (0);
	}
}
