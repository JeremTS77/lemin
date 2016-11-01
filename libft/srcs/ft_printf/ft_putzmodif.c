/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putzmodif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 17:05:03 by jelefebv          #+#    #+#             */
/*   Updated: 2015/02/13 14:57:38 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <string.h>
#include <limits.h>

char	*ft_putzx_maj(size_t nb)
{
	int		i;
	size_t	hex;
	char	*str;

	hex = nb;
	i = 0;
	while (hex != 0)
	{
		hex = hex / 16;
		i++;
	}
	hex = nb;
	if (!(str = (char *)malloc(sizeof(char) * i + 26)))
		return (0);
	str[0] = '\0';
	if (nb == 0)
		str = ft_keepstring_inv('0', str);
	while (i > 0)
	{
		--i;
		hex = nb % 16;
		nb = nb / 16;
		str[i] = ((hex / 10) > 0) ? hex % 10 + 'A' : hex + '0';
	}
	return (str);
}

char	*ft_putzx(size_t nb)
{
	int		i;
	size_t	hex;
	char	*str;

	hex = nb;
	i = 0;
	while (hex != 0)
	{
		hex = hex / 16;
		i++;
	}
	hex = nb;
	if (!(str = (char *)malloc(sizeof(char) * i + 26)))
		return (0);
	str[0] = '\0';
	if (nb == 0)
		str = ft_keepstring_inv('0', str);
	while (i > 0)
	{
		--i;
		hex = nb % 16;
		nb = nb / 16;
		str[i] = ((hex / 10) > 0) ? hex % 10 + 'a' : hex + '0';
	}
	return (str);
}

char	*ft_putuz(size_t n)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 42)))
		return (0);
	str[0] = '\0';
	if (n == 0)
		str = ft_keepstring_inv('0', str);
	while (n > 0)
	{
		str = ft_keepstring_inv('0' + n % 10, str);
		n /= 10;
	}
	return (str);
}

char	*ft_putznbr(ssize_t n)
{
	char		*dst;
	ssize_t		tmp;
	int			len;

	tmp = n > 0 ? n : -n;
	len = 1;
	if (n == LLONG_MIN)
		return ("-9223372036854775808");
	while ((tmp /= 10) != 0)
		len++;
	tmp = n > 0 ? n : -n;
	if (n < 0)
		len++;
	if (!(dst = ft_strnew(len)))
		return (0);
	while (len--)
	{
		dst[len] = '0' + tmp % 10;
		tmp /= 10;
	}
	if (n < 0)
		dst[0] = '-';
	return (dst);
}

char	*ft_putzo(size_t nb)
{
	int		i;
	size_t	hex;
	char	*str;

	hex = nb;
	i = 0;
	while (hex != 0)
	{
		hex = hex / 8;
		i++;
	}
	hex = nb;
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (0);
	str[i] = '\0';
	if (nb == 0)
		str[0] = '0';
	while (i > 0)
	{
		--i;
		hex = nb % 8;
		nb = nb / 8;
		str[i] = hex + '0';
	}
	return (str);
}
