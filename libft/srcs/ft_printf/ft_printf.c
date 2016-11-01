/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 14:57:00 by jelefebv          #+#    #+#             */
/*   Updated: 2015/02/13 14:57:00 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_flag(t_flag *list, const char *format)
{
	list->hash = 0;
	list->zero = 0;
	list->minus = 0;
	list->plus = 0;
	list->space = 0;
	list->point = 0;
	list->nbpoint = 0;
	list->index = 0;
	list->l = 0;
	list->h = 0;
	list->j = 0;
	list->z = 0;
	list->tmp = 0;
	list->nbchar = 0;
	list->cnull = 0;
	list->null = 0;
	list->string = ft_strnew(1);
	list->format = format;
}

int		ft_printf(const char *format, ...)
{
	static int	result;
	va_list		ap;

	result = 0;
	va_start(ap, format);
	result = us_printf((char *)format, result, &ap);
	va_end(ap);
	return (result);
}

int		us_printf(const char *format, int result, va_list *ap)
{
	t_flag	flagprintf;

	ft_init_flag(&flagprintf, format);
	while (*format != '%' && *format && *format++)
		flagprintf.index++;
	result += ft_putstr_len(flagprintf.format, flagprintf.index);
	if (!(*format))
		return (result);
	flagprintf.format = format + 1;
	if (*format++ == '%')
	{
		if (*format == '\0')
			return (result);
		if (*format == 'n')
			ft_printf_n(va_arg(*ap, int *), result);
		else
		{
			ft_parseflag(&flagprintf);
			result += ft_trimprintf(&flagprintf, ap);
			if (flagprintf.cnull == 1)
				result--;
		}
	}
	return (us_printf(++flagprintf.format, result, ap));
}
