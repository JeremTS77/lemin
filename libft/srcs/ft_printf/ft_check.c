/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 14:58:46 by jelefebv          #+#    #+#             */
/*   Updated: 2015/02/13 14:58:47 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

char	*ft_checkarg(va_list *ap, t_flag *flag)
{
	char	*str;

	flag->c = *(flag->format);
	if ((*(flag->format) == 'd' || *(flag->format) == 'i') && flag->h >= 2)
		str = ft_puthhnbr((char)va_arg(*ap, int));
	else if (*(flag->format) == 'p')
		str = ft_straddr(va_arg(*ap, void *));
	else if ((*(flag->format) == 'd' || *(flag->format) == 'i') && flag->h == 1)
		str = ft_puthnbr((short)va_arg(*ap, int));
	else if (*(flag->format) == 's')
		str = ft_printf_s(va_arg(*ap, char *), flag);
	else if ((*(flag->format) == 'd' || *(flag->format) == 'i')
		&& flag->l == 0 && flag->h == 0 && flag->j == 0 && flag->z == 0)
		str = ft_itoa((long long)va_arg(*ap, int));
	else if ((*(flag->format) == 'D') ||
		((*(flag->format) == 'd' || *(flag->format) == 'i') && flag->l == 1))
	{
		flag->l = 0;
		str = ft_itoa((long long)va_arg(*ap, long));
	}
	else
		str = ft_checkarg_bis(ap, flag);
	return (str);
}

char	*ft_checkarg_bis(va_list *ap, t_flag *flag)
{
	char	*str;

	if (*(flag->format) == 'o' && flag->l == 0 && flag->h == 0
			&& flag->j == 0 && flag->z == 0)
		str = ft_printf_o(va_arg(*ap, unsigned int));
	else if ((*(flag->format) == 'O') || (*(flag->format) == 'o'
			&& flag->l == 1))
	{
		flag->l = 0;
		str = ft_putlo(va_arg(*ap, unsigned long));
	}
	else if (*(flag->format) == 'o' && flag->l > 1)
	{
		flag->l = 0;
		str = ft_putllo(va_arg(*ap, unsigned long long));
	}
	else if (*(flag->format) == 'o' && flag->h == 1)
	{
		flag->h = 0;
		str = ft_putho((unsigned short)va_arg(*ap, int));
	}
	else
		str = ft_checkarg_ter(ap, flag);
	return (str);
}

char	*ft_checkarg_ter(va_list *ap, t_flag *flag)
{
	char	*str;

	if (*(flag->format) == 'o' && flag->h > 1)
	{
		flag->h = 0;
		str = ft_puthho((unsigned char)va_arg(*ap, int));
	}
	else if (flag->z == 1)
		str = ft_checkz(ap, flag);
	else if (*(flag->format) == 'u' && flag->l == 0
			&& flag->h == 0 && flag->j == 0 && flag->z == 0)
		str = ft_putu(va_arg(*ap, unsigned int));
	else if (*(flag->format) == 'U' || (*(flag->format) == 'u' && flag->l == 1))
	{
		flag->l = 0;
		str = ft_putulnbr(va_arg(*ap, unsigned long));
	}
	else if (*(flag->format) == 'u' && flag->l > 1)
	{
		flag->l = 0;
		str = ft_putullnbr(va_arg(*ap, unsigned long long));
	}
	else
		str = ft_checkarg_quater(ap, flag);
	return (str);
}

char	*ft_checkarg_quater(va_list *ap, t_flag *flag)
{
	char	*str;

	if (*(flag->format) == 'u' && flag->h == 1)
	{
		flag->h = 0;
		str = ft_putuhnbr((unsigned short)va_arg(*ap, int));
	}
	else if (*(flag->format) == 'u' && flag->h > 1)
	{
		flag->h = 0;
		str = ft_putuhhnbr((unsigned char)va_arg(*ap, int));
	}
	else if ((*(flag->format) == 'd' || *(flag->format) == 'i') && flag->l >= 2)
	{
		flag->l = 0;
		str = ft_itoa(va_arg(*ap, long long));
	}
	else if (*(flag->format) == 'x' || *(flag->format) == 'X')
		str = ft_check_x(ap, flag);
	else if (flag->j == 1)
		str = ft_checkj(ap, flag);
	else
		str = ft_chartostr(*(flag->format));
	return (str);
}
