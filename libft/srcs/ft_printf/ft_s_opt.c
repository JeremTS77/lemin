/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_opt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 15:45:59 by jelefebv          #+#    #+#             */
/*   Updated: 2016/03/22 11:36:56 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_s_opt(t_flag *flag, va_list *ap)
{
	int			result;
	wchar_t		*ws;

	result = 0;
	flag->l = 0;
	ws = va_arg(*ap, wchar_t *);
	if (!ws)
		result = ft_putstr("(null)");
	else
		result = ft_wflag(flag, ws);
	return (result);
}
