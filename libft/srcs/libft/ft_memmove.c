/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 12:05:10 by jelefebv          #+#    #+#             */
/*   Updated: 2016/03/22 12:02:40 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*tmp;
	const char	*tmp2;

	tmp = dst;
	tmp2 = src;
	if (tmp2 <= tmp)
	{
		tmp = tmp + len - 1;
		tmp2 = tmp2 + len - 1;
		while (len--)
		{
			*tmp-- = *tmp2--;
		}
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
