/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 17:10:50 by jelefebv          #+#    #+#             */
/*   Updated: 2014/12/29 17:47:51 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *source, size_t size1)
{
	char		*strdest;
	const char	*src;
	size_t		n;
	size_t		len;

	strdest = dest;
	src = source;
	n = size1;
	while (n-- != 0 && *strdest != '\0')
		strdest++;
	len = strdest - dest;
	n = size1 - len;
	if (n == 0)
		return (len + ft_strlen(src));
	while (*src != '\0')
	{
		if (n != 1)
		{
			*strdest++ = *src;
			n--;
		}
		src++;
	}
	*strdest = '\0';
	return (len + (src - source));
}
