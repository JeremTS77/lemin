/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jelefebv <jelefebv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 17:11:46 by jelefebv          #+#    #+#             */
/*   Updated: 2014/12/29 17:47:51 by jelefebv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[i2] != '\0' && n-- > 0)
	{
		s1[i++] = s2[i2++];
	}
	s1[i] = '\0';
	return (s1);
}
