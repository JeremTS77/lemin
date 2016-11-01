/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 14:57:20 by jelefebv          #+#    #+#             */
/*   Updated: 2015/02/13 14:58:09 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_opt_minus(t_flag *list, int nb)
{
	int		i;

	i = 0;
	if (nb < list->nbchar)
	{
		while (i < (list->nbchar - nb))
		{
			list->string = ft_keepstring(' ', list->string);
			i++;
		}
	}
	return (i);
}

int		ft_opt_plus(int isneg, t_flag *list)
{
	int		nb;

	nb = 0;
	if (isneg == 0)
	{
		list->string = ft_keepstring_inv('+', list->string);
		nb = 1;
	}
	return (nb);
}

int		ft_opt_space(int isneg, t_flag *list)
{
	int		nb;

	nb = 0;
	if (isneg == 0)
	{
		list->string = ft_keepstring_inv(' ', list->string);
		nb = 1;
	}
	return (nb);
}

int		ft_opt_zero(t_flag *list, int nb, int isneg, char c)
{
	int		i;

	i = 0;
	list->plus == 1 && isneg == 0 ? nb++ : nb;
	list->space == 1 && isneg == 0 && nb != 2 ? nb++ : nb;
	list->cnull == 1 ? nb++ : nb;
	if (nb < list->nbchar)
	{
		while (i < (list->nbchar - nb))
		{
			if (c == 'p' && list->nbchar == 5)
				list->string = ft_strjoin(list->string, "00");
			if (c != 'p' && list->point == 0)
				list->string = ft_keepstring_inv('0', list->string);
			else if (c == 'c' && list->cnull == 1 && list->point == 1)
				list->string = ft_keepstring_inv('0', list->string);
			else if (list->point == 1)
				list->string = ft_keepstring_inv(' ', list->string);
			i++;
		}
	}
	return (i);
}

int		ft_opt_hash(t_flag *list, char c)
{
	int		nb;

	nb = 0;
	if (c == 'x')
	{
		list->string = ft_keepstring_inv('x', list->string);
		list->string = ft_keepstring_inv('0', list->string);
		nb = 2;
	}
	else if (c == 'X')
	{
		list->string = ft_keepstring_inv('X', list->string);
		list->string = ft_keepstring_inv('0', list->string);
		nb = 2;
	}
	else if (c == 'o' || c == 'O')
	{
		list->string = ft_keepstring_inv('0', list->string);
		nb = 1;
	}
	return (nb);
}
