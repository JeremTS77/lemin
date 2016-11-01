/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 17:02:42 by jelefebv          #+#    #+#             */
/*   Updated: 2016/03/22 12:04:33 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_itoa(long long n)
{
	char				*dst;
	unsigned long long	tmp;
	int					len;

	tmp = n > 0 ? n : -n;
	len = 1;
	while ((tmp /= 10) != 0)
		len++;
	tmp = n > 0 ? n : -n;
	if (n < 0)
		len++;
	if (!(dst = ft_strnew(len)))
		return (0);
	while (len--)
	{
		dst[len] = tmp % 10 + '0';
		tmp /= 10;
	}
	if (n < 0)
		dst[0] = '-';
	return (dst);
}
