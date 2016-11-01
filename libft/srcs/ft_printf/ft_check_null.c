/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_null.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 14:55:10 by jelefebv          #+#    #+#             */
/*   Updated: 2015/02/13 14:57:24 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int		ft_check_null(char c, va_list ap)
{
	va_list	tmp;

	va_copy(tmp, ap);
	if (c == 'o' || c == 'x')
		return (va_arg(tmp, unsigned int) == 0) ? 1 : 0;
	if (c == 'O' || c == 'X')
		return (va_arg(tmp, unsigned long) == 0) ? 1 : 0;
	return (0);
}
