/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdmodif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 23:33:55 by jelefebv          #+#    #+#             */
/*   Updated: 2015/02/13 14:57:52 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include <string.h>
#include <limits.h>

char	*ft_puthnbr(short n)
{
	char	*str;
	int		flag;

	flag = 0;
	if (!(str = (char *)malloc(sizeof(char) * 21)))
		return (NULL);
	str[0] = '\0';
	if (n == SHRT_MIN)
		return (ft_itoa(SHRT_MIN));
	if (n < 0)
	{
		flag = 1;
		n = n * -1;
	}
	if (n < 10)
		str = ft_keepstring('0' + n, str);
	else
	{
		str = ft_puthnbr(n / 10);
		str = ft_keepstring('0' + n % 10, str);
	}
	if (flag == 1)
		return (ft_strjoin("-", str));
	return (str);
}

char	*ft_puthhnbr(signed char n)
{
	char	*str;
	int		flag;

	flag = 0;
	if (!(str = (char *)malloc(sizeof(char) * 21)))
		return (NULL);
	str[0] = '\0';
	if (n == SCHAR_MIN)
		return (ft_itoa(SCHAR_MIN));
	if (n < 0)
	{
		flag = 1;
		n = n * -1;
	}
	if (n < 10)
		str = ft_keepstring('0' + (char)n, str);
	else
	{
		str = ft_puthhnbr(n / 10);
		str = ft_keepstring('0' + (char)n % 10, str);
	}
	if (flag == 1)
		return (ft_strjoin("-", str));
	return (str);
}

char	*ft_putlnbr(long n)
{
	char	*str;
	int		flag;

	flag = 0;
	if (!(str = (char *)malloc(sizeof(char) * 21)))
		return (NULL);
	str[0] = '\0';
	if (n == LONG_MIN)
		return (ft_itoa(LONG_MIN));
	if (n < 0)
	{
		flag = 1;
		n = n * -1;
	}
	if (n < 10)
		str = ft_keepstring('0' + n, str);
	else
	{
		str = ft_putlnbr(n / 10);
		str = ft_keepstring('0' + n % 10, str);
	}
	if (flag == 1)
		return (ft_strjoin("-", str));
	return (str);
}

char	*ft_putllnbr(long long n)
{
	char	*str;
	int		flag;

	flag = 0;
	if (!(str = (char *)malloc(sizeof(char) * 21)))
		return (NULL);
	str[0] = '\0';
	if (n == LLONG_MIN)
		return (ft_itoa(LLONG_MIN));
	if (n < 0)
	{
		flag = 1;
		n = n * -1;
	}
	if (n < 10)
		str = ft_keepstring('0' + n, str);
	else
	{
		str = ft_putllnbr(n / 10);
		str = ft_keepstring('0' + n % 10, str);
	}
	if (flag == 1)
		return (ft_strjoin("-", str));
	return (str);
}

char	*ft_putjd(intmax_t n)
{
	char	*str;
	int		flag;

	flag = 0;
	if (!(str = (char *)malloc(sizeof(char) * 21)))
		return (NULL);
	str[0] = '\0';
	if (n == INTMAX_MIN)
		return (ft_itoa(INTMAX_MIN));
	if (n < 0)
	{
		flag = 1;
		n = n * -1;
	}
	if (n < 10)
		str = ft_keepstring('0' + n, str);
	else
	{
		str = ft_putjd(n / 10);
		str = ft_keepstring('0' + n % 10, str);
	}
	if (flag == 1)
		return (ft_strjoin("-", str));
	return (str);
}
