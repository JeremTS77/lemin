/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 15:00:57 by jelefebv          #+#    #+#             */
/*   Updated: 2016/03/22 11:23:47 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static char		*ft_stradd_norme(char temp, char *string)
{
	if (temp > '9')
	{
		temp += 39;
		return (ft_keepstring(temp, string));
	}
	else
		return (ft_keepstring(temp, string));
}

char			*ft_straddr(void *str)
{
	long int			div;
	char				temp;
	char				*string;
	unsigned long int	n;

	n = (unsigned long int)str;
	div = 16;
	string = ft_strnew(1);
	string = ft_strjoin(string, "0x");
	if (n == 0)
	{
		string = ft_keepstring('0', string);
		return (string);
	}
	while (n / div >= 16)
		div *= 16;
	while (div > 0)
	{
		temp = '0' + n / div;
		string = ft_stradd_norme(temp, string);
		n %= div;
		div /= 16;
	}
	return (string);
}
