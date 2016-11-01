/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putullnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 16:41:41 by jelefebv          #+#    #+#             */
/*   Updated: 2015/02/13 14:57:45 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

char	*ft_putullnbr(unsigned long long n)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 21)))
		return (NULL);
	str[0] = '\0';
	if (n < 10)
		str = ft_keepstring('0' + n, str);
	else
	{
		str = ft_putullnbr(n / 10);
		str = ft_keepstring('0' + n % 10, str);
	}
	return (str);
}

char	*ft_putuhhnbr(unsigned char n)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 21)))
		return (NULL);
	str[0] = '\0';
	if (n < 10)
		str = ft_keepstring('0' + n, str);
	else
	{
		str = ft_putuhhnbr(n / 10);
		str = ft_keepstring('0' + n % 10, str);
	}
	return (str);
}

char	*ft_putulnbr(unsigned long n)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 21)))
		return (NULL);
	str[0] = '\0';
	if (n < 10)
		str = ft_keepstring('0' + n, str);
	else
	{
		str = ft_putulnbr(n / 10);
		str = ft_keepstring('0' + n % 10, str);
	}
	return (str);
}

char	*ft_putuhnbr(unsigned short n)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 21)))
		return (NULL);
	str[0] = '\0';
	if (n < 10)
		str = ft_keepstring('0' + n, str);
	else
	{
		str = ft_putuhnbr(n / 10);
		str = ft_keepstring('0' + n % 10, str);
	}
	return (str);
}

char	*ft_putju(uintmax_t n)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 21)))
		return (NULL);
	str[0] = '\0';
	if (n < 10)
		str = ft_keepstring('0' + n, str);
	else
	{
		str = ft_putju(n / 10);
		str = ft_keepstring('0' + n % 10, str);
	}
	return (str);
}
