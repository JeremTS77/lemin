/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_triprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 13:19:09 by jelefebv          #+#    #+#             */
/*   Updated: 2015/02/13 14:57:33 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_trimprintf(t_flag *flag, va_list *ap)
{
	int			result;
	int			nbr;

	result = 0;
	flag->null = ft_check_null(*(flag->format), *ap);
	if (*(flag->format) == '%')
		flag->string = ft_chartostr('%');
	else if ((*(flag->format) == 'C') || (*(flag->format) == 'c'
				&& flag->l >= 1))
	{
		flag->l = 0;
		result += ft_putwchar(va_arg(*ap, wint_t));
	}
	else if (*(flag->format) == 'c')
		flag->string = ft_chartostr_res((char)va_arg(*ap, int), &result, flag);
	else if ((*(flag->format) == 'S') || (*(flag->format) == 's'
				&& flag->l >= 1))
		result = ft_s_opt(flag, ap);
	else if (*(flag->format) == 'n')
		result += ft_printf_n(va_arg(*ap, int *), result);
	else
		flag->string = ft_checkarg(ap, flag);
	nbr = ft_parsing(flag);
	result += ft_putstr_len(flag->string, nbr);
	return (result);
}

void	ft_parse_point(t_flag *flagprintf, const char *str)
{
	flagprintf->point = 1;
	str++;
	if (*str >= '1' && *str <= '9')
	{
		flagprintf->nbpoint = ft_atoi(str);
		flagprintf->format += ft_nbrlen(flagprintf->nbpoint) + 1;
	}
	else
		flagprintf->format += 1;
}

void	ft_parseflag(t_flag *flagprintf)
{
	const char	*s;

	s = flagprintf->format;
	if ((*s == '#') || (*s == '0') || (*s == '-') || (*s == '+') || (*s == ' ')
	|| (*s == 'l') || (*s == 'h') || (*s == 'j') || (*s == 'z') || (*s == '.'))
	{
		flagprintf->hash = (*s == '#') ? 1 : flagprintf->hash;
		flagprintf->zero = (*s == '0') ? 1 : flagprintf->zero;
		flagprintf->minus = (*s == '-') ? 1 : flagprintf->minus;
		flagprintf->plus = (*s == '+') ? 1 : flagprintf->plus;
		flagprintf->space = (*s == ' ') ? 1 : flagprintf->space;
		flagprintf->l += (*s == 'l') ? 1 : 0;
		flagprintf->h += (*s == 'h') ? 1 : 0;
		flagprintf->j = (*s == 'j') ? 1 : 0;
		flagprintf->z = (*s == 'z') ? 1 : 0;
		if (*s == '.')
		{
			ft_parse_point(flagprintf, s);
		}
		else
			flagprintf->format = ++s;
		ft_parseflag(flagprintf);
	}
	else if (*s >= '1' && *s <= '9')
		ft_parsflag_bis(flagprintf, s);
}

int		ft_wflag(t_flag *flag, wchar_t *str)
{
	int		result;
	int		wlen;

	result = 0;
	wlen = ft_lenwstr(str);
	if (flag->minus && flag->nbchar > wlen)
	{
		result += ft_putwstr(str);
		result += ft_wspace(flag, wlen);
	}
	else if (flag->zero && flag->nbchar > wlen)
	{
		result += ft_wzero(flag, wlen);
		result += ft_putwstr(str);
	}
	else if (flag->nbchar > wlen)
	{
		result += ft_wspace(flag, wlen);
		result += ft_putwstr(str);
	}
	else
		result = ft_wflag_bis(flag, str);
	return (result);
}

int		ft_wflag_bis(t_flag *flag, wchar_t *str)
{
	int		result;

	result = 0;
	if (flag->point)
	{
		if (flag->zero)
		{
			while (flag->nbchar)
			{
				flag->nbchar--;
				result += ft_putchar('0');
			}
		}
		result += ft_wflag_ter(flag, str);
	}
	else
		result = ft_putwstr(str);
	return (result);
}
