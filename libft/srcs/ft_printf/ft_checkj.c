/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 14:55:23 by jelefebv          #+#    #+#             */
/*   Updated: 2015/02/13 14:57:25 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

char	*ft_checkj(va_list *ap, t_flag *flag)
{
	char	*str;

	if (*(flag->format) == 'i' || *(flag->format) == 'd')
		str = ft_putjd(va_arg(*ap, intmax_t));
	else if (*(flag->format) == 'o')
		str = ft_putjo(va_arg(*ap, uintmax_t));
	else if (*(flag->format) == 'u')
		str = ft_putju(va_arg(*ap, uintmax_t));
	else if (*(flag->format) == 'x')
		str = ft_putjx(va_arg(*ap, uintmax_t));
	else if (*(flag->format) == 'X')
		str = ft_putjx_maj(va_arg(*ap, uintmax_t));
	else
		str = ft_chartostr(*(flag->format));
	return (str);
}
