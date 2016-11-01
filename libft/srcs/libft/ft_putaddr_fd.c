/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 13:55:52 by jelefebv          #+#    #+#             */
/*   Updated: 2016/03/22 12:01:57 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int				ft_putaddr_fd(void *str, int fd)
{
	long int			div;
	int					count;
	char				temp;
	unsigned long int	n;

	count = 0;
	n = (unsigned long int)str;
	div = 16;
	count += write(fd, "0x", 2);
	while (n / div >= 16)
		div *= 16;
	while (div > 0)
	{
		temp = '0' + n / div;
		if (temp > '9')
		{
			temp += 39;
			count += write(fd, &temp, 1);
		}
		else
			count += write(fd, &temp, 1);
		n %= div;
		div /= 16;
	}
	return (count);
}
