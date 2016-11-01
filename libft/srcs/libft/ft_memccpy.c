/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 11:19:56 by jelefebv          #+#    #+#             */
/*   Updated: 2016/03/22 12:03:27 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char		*dest;
	const char	*src;

	src = s2;
	dest = s1;
	while (n--)
	{
		if (*src == c)
		{
			*dest++ = *src++;
			return (dest);
		}
		*dest++ = *src++;
	}
	return (NULL);
}
