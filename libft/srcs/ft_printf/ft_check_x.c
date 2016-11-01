/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 14:55:16 by jelefebv          #+#    #+#             */
/*   Updated: 2015/02/13 14:57:25 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

char	*ft_check_x(va_list *ap, t_flag *flag)
{
	char	*str;

	if (*(flag->format) == 'x' && flag->l == 0 && flag->h == 0 && flag->j == 0
			&& flag->z == 0)
		str = ft_putx(va_arg(*ap, unsigned int));
	else if (*(flag->format) == 'x' && flag->j == 1)
	{
		flag->j = 0;
		str = ft_putjx(va_arg(*ap, uintmax_t));
	}
	else if (*(flag->format) == 'X' && flag->j == 1)
	{
		flag->j = 0;
		str = ft_putjx_maj(va_arg(*ap, uintmax_t));
	}
	else if (*(flag->format) == 'X' && flag->l == 0 && flag->h == 0)
		str = ft_putx_maj(va_arg(*ap, unsigned int));
	else if (*(flag->format) == 'x' && flag->l == 1)
	{
		flag->l = 0;
		str = ft_putlx(va_arg(*ap, unsigned long));
	}
	else
		str = ft_check_x_bis(ap, flag);
	return (str);
}

char	*ft_check_x_bis(va_list *ap, t_flag *flag)
{
	char	*str;

	if (*(flag->format) == 'X' && flag->l > 1)
	{
		flag->l = 0;
		str = ft_putllx_maj(va_arg(*ap, unsigned long long));
	}
	else if (*(flag->format) == 'x' && flag->h == 1)
	{
		flag->h = 0;
		str = ft_puthx((unsigned short)va_arg(*ap, int));
	}
	else if (*(flag->format) == 'X' && flag->h == 1)
	{
		flag->h = 0;
		str = ft_puthx_maj((unsigned short)va_arg(*ap, int));
	}
	else if (*(flag->format) == 'x' && flag->h > 1)
	{
		flag->h = 0;
		str = ft_puthhx((unsigned char)va_arg(*ap, int));
	}
	else
		str = ft_check_x_ter(ap, flag);
	return (str);
}

char	*ft_check_x_ter(va_list *ap, t_flag *flag)
{
	char	*str;

	if (*(flag->format) == 'X' && flag->h > 1)
	{
		flag->h = 0;
		str = ft_puthhx_maj((unsigned char)va_arg(*ap, int));
	}
	else if (*(flag->format) == 'X' && flag->l == 1)
	{
		flag->l = 0;
		str = ft_putlx_maj(va_arg(*ap, unsigned long));
	}
	else if (*(flag->format) == 'x' && flag->l > 1)
	{
		flag->l = 0;
		str = ft_putllx(va_arg(*ap, unsigned long long));
	}
	else
		str = ft_check_x_quater(ap, flag);
	return (str);
}

char	*ft_check_x_quater(va_list *ap, t_flag *flag)
{
	char	*str;

	if (*(flag->format) == 'x' && flag->z == 1)
	{
		flag->j = 0;
		str = ft_putzx(va_arg(*ap, size_t));
	}
	else if (*(flag->format) == 'X' && flag->z == 1)
	{
		flag->j = 0;
		str = ft_putzx_maj(va_arg(*ap, size_t));
	}
	else
		str = ft_strdup("(null)");
	return (str);
}
