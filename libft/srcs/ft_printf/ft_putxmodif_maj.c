/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxmodif_maj.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 16:00:34 by jelefebv          #+#    #+#             */
/*   Updated: 2015/02/13 14:57:40 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

char	*ft_putllx_maj(unsigned long long nb)
{
	int					i;
	unsigned long long	hex;
	char				*str;

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

char	*ft_putlx_maj(unsigned long nb)
{
	int				i;
	unsigned long	hex;
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

char	*ft_puthx_maj(unsigned short nb)
{
	int				i;
	unsigned int	hex;
	char			*str;

	hex = (unsigned int)nb;
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

char	*ft_puthhx_maj(unsigned char nb)
{
	int				i;
	unsigned int	hex;
	char			*str;

	hex = (unsigned int)nb;
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

char	*ft_putjx_maj(uintmax_t nb)
{
	int			i;
	uintmax_t	hex;
	char		*str;

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
