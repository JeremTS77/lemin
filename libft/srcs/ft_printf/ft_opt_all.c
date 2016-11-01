/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opt_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 14:55:54 by jelefebv          #+#    #+#             */
/*   Updated: 2015/02/13 14:57:26 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_opt_all(int nbr, int isneg, t_flag *list, char c)
{
	if (c != 'S' && c != 'C')
	{
		if ((c == 'd' || c == 'i' || c == 'D' || c == 'u' || c == 'U'
				|| c == 'o' || c == 'O' || c == 'x' || c == 'X'))
			nbr = (list->point == 1) ? ft_opt_point_nbr(nbr, list, isneg) : nbr;
		else if (c == 'p')
			list->point == 1 ? nbr = ft_opt_point_adr(nbr, list) : nbr;
		else if (c == 's')
			nbr = (list->point == 1) ? (int)ft_strlen(list->string) : nbr;
		if ((c == 'd' || c == 'i' || c == 'D' || c == 'u' || c == 'U'
			|| c == 'o' || c == 'O' || c == 'x' || c == 'X' || c == 's'
			|| c == 'p' || list->cnull == 1 || c == 'c') && list->minus == 0)
			nbr += (list->zero == 1) ? ft_opt_zero(list, nbr, isneg, c) : 0;
		if ((c == 'd' || c == 'i' || c == 'D') && list->plus == 0
			&& list->space == 1)
			nbr += (list->space == 1) ? ft_opt_space(isneg, list) : 0;
		if (c == 'd' || c == 'i' || c == 'D' || c == 'u' || c == 'U' || c == 'o'
			|| c == 'O' || c == 'x' || c == 'X' || c == 'c' || c == '\0')
			nbr += (list->minus == 1) ? ft_opt_minus(list, nbr) : 0;
		if ((c == 'd' || c == 'i' || c == 'u' || c == 'o' || c == 'x'
				|| c == 'X' || c == 'D' || c == 'U' || c == 'O') && isneg == 1)
			list->string = ft_keepstring_inv('-', list->string);
		ft_opt_all_bis(&nbr, isneg, list, c);
	}
	return (nbr);
}

void	ft_opt_all_bis(int *nbr, int isneg, t_flag *list, char c)
{
	if (c == 'd' || c == 'i' || c == 'D')
		*nbr += (list->plus == 1) ? ft_opt_plus(isneg, list) : 0;
	if ((c == 'x' || c == 'X' || c == 'O' || (list->point == 0 &&
					c == 'o')) && list->null == 0)
		*nbr += (list->hash == 1) ? ft_opt_hash(list, c) : 0;
	if (list->point == 1 && list->nbpoint == 0)
	{
		if (!(c == 'c' && list->zero == 1))
			*nbr = ft_opt_point_null(list, c);
	}
	if (list->cnull == 0)
	{
		if (list->nbchar > *nbr && list->minus == 1)
			*nbr += ft_glhfmin(list, *nbr);
		if (list->nbchar > *nbr && list->minus == 0)
			*nbr += ft_glhf(list, *nbr);
	}
	else
	{
		if (list->nbchar > *nbr && list->minus == 1)
			*nbr += ft_glhfmin(list, *nbr + 1);
		if (list->nbchar > *nbr && list->minus == 0)
			*nbr += ft_glhf(list, *nbr + 1);
	}
}
