/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 14:44:57 by jelefebv          #+#    #+#             */
/*   Updated: 2016/03/22 12:04:06 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <wchar.h>

int		ft_lenwchar(wint_t x)
{
	size_t			j;

	j = 1;
	if (x <= 0x7F)
		return (j);
	if (x > 0x1FFFFF)
		return (-1);
	while (1)
	{
		if (!(x >>= 6))
			break ;
		j++;
	}
	return (j);
}
