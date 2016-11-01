/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 14:59:37 by jelefebv          #+#    #+#             */
/*   Updated: 2016/03/22 11:31:39 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int				ft_addrlen(void *str)
{
	long int			div;
	int					count;
	char				temp;
	unsigned long int	n;

	count = 0;
	n = (unsigned long int)str;
	div = 16;
	while (n / div >= 16)
		div *= 16;
	while (div > 0)
	{
		temp = '0' + n / div;
		if (temp > '9')
		{
			temp += 39;
			count++;
		}
		else
			count++;
		n %= div;
		div /= 16;
	}
	return (count);
}
