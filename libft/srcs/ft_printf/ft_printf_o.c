/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 14:58:03 by jelefebv          #+#    #+#             */
/*   Updated: 2015/02/13 14:58:04 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

char	*ft_printf_o_maj(long unsigned int nb)
{
	int					i;
	long unsigned int	hex;
	char				*str;

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

char	*ft_printf_o(unsigned int nb)
{
	int				i;
	unsigned int	hex;
	char			*str;

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
