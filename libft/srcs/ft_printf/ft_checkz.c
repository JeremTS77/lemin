/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 14:55:42 by jelefebv          #+#    #+#             */
/*   Updated: 2015/02/13 14:57:25 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

char	*ft_checkz(va_list *ap, t_flag *flag)
{
	char	*str;

	if (*(flag->format) == 'i' || *(flag->format) == 'd')
		str = ft_putznbr(va_arg(*ap, ssize_t));
	else if (*(flag->format) == 'o')
		str = ft_putzo(va_arg(*ap, size_t));
	else if (*(flag->format) == 'u' || *(flag->format) == 'U')
		str = ft_putuz(va_arg(*ap, size_t));
	else if (*(flag->format) == 'x')
		str = ft_putzx(va_arg(*ap, size_t));
	else if (*(flag->format) == 'X')
		str = ft_putzx_maj(va_arg(*ap, size_t));
	else
		str = ft_chartostr(*(flag->format));
	return (str);
}
