/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnormal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 14:56:39 by jelefebv          #+#    #+#             */
/*   Updated: 2015/02/13 14:57:50 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	*ft_putx_maj(unsigned int nb)
{
	int				i;
	unsigned int	hex;
	char			*str;

	hex = nb;
	i = 0;
	while (hex != 0)
	{
		hex = hex / 16;
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
		hex = nb % 16;
		nb = nb / 16;
		str[i] = ((hex / 10) > 0) ? hex % 10 + 'A' : hex + '0';
	}
	return (str);
}

char	*ft_putx(unsigned int nb)
{
	int				i;
	unsigned int	hex;
	char			*str;

	hex = nb;
	i = 0;
	while (hex != 0)
	{
		hex = hex / 16;
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
		hex = nb % 16;
		nb = nb / 16;
		str[i] = ((hex / 10) > 0) ? hex % 10 + 'a' : hex + '0';
	}
	return (str);
}

char	*ft_putu(unsigned int n)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 1)))
		return (NULL);
	str[0] = '\0';
	if (n < 10)
		str = ft_keepstring('0' + n, str);
	else
	{
		str = ft_putu(n / 10);
		str = ft_keepstring('0' + n % 10, str);
	}
	return (str);
}
