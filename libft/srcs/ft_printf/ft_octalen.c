/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octalen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 15:02:11 by jelefebv          #+#    #+#             */
/*   Updated: 2015/02/13 15:02:16 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_octalen(unsigned int nb)
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
	return (ft_strlen(str));
}
